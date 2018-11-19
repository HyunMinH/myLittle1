#include <stdio.h>
#include <stdlib.h>
#define MIN_ORDER 2
#define KEY_LENGTH 6
#define BUCKET_SIZE 4
typedef struct Record
{
    int key;
    char* name;
} record;

typedef struct Leaf
{
    int header;
    int count;  // 저장된 record의 갯수
    record** pRecord; // 저장된 record의 주소를 가리키는 pointer의 배열
} leaf;
typedef struct Directory
{
    int header;
    int divCount;  // directory의 header와 같은 header를 가진 leaf pair의 갯수
    leaf** entry;
} directory;
// 키를 가지고 데이터를 검색한다.
record* retrieval(int key, directory* dir);
// 레코드를 받아서 저장한다. (return value : 성공=1, 실패=0)
int insertRecord(record* rec, directory* dir);
// 키를 받아서 레코드를 찾아 지운다. (return value : 성공=1, 실패=0)
int delRecord(int key, directory* dir);
// 테이블을 출력한다.
void printTable(directory* dir);
// 보조함수들
int pow_2(int p);
int makePseudokey(int key);
int foreget(int k, int n);
///////////////////////////////////////////////////////
///  main함수
///////////////////////////////////////////////////////
void main()
{
    FILE* fp;
    int i;
    char ch[100], c;
    char* name;
    // leaf와 디렉토리를 초기화한다.
    directory* dir;
    dir = (directory*)malloc(sizeof(directory));
    dir->header = MIN_ORDER;
    dir->divCount = pow_2(MIN_ORDER-1);
    dir->entry = (leaf**)malloc(sizeof(leaf*) * pow_2(MIN_ORDER));
    for (i=0; i<pow_2(MIN_ORDER); i++)
    {
        dir->entry[i] = (leaf*)malloc(sizeof(leaf));
        dir->entry[i]->header = 2;
        dir->entry[i]->count = 0;
        dir->entry[i]->pRecord = (record**)malloc(sizeof(record*)*BUCKET_SIZE);
    }
    // insertion loof
    fp = fopen("e_hashing.txt", "r");
    while (fscanf(fp, "%s", ch) == 1)
    {
        record* rec = (record*)malloc(sizeof(record));
        name = (char*)malloc(sizeof(char)*20);
        rec->key = atoi(ch);
        if (fscanf(fp, "%s", name) == 1)
            rec->name = name;
        else
            break;
        insertRecord(rec, dir);
        printf("\n***  key : %d, name : %s 인 record를 저장, pseudokey : %d ***\n",
               rec->key, rec->name, makePseudokey(rec->key));
        printTable(dir);
        printf("\n\nPress Enter!!\n");
        scanf("%c", &c);
    }
    fclose(fp);
    // deletion loof
    fp = fopen("e_hashing.txt", "r");
    name = (char*)malloc(sizeof(char)*20);
    while (fscanf(fp, "%s", ch) == 1)
    {
        int key = atoi(ch);
        fscanf(fp, "%s", name);
        delRecord(key, dir);
        printf("\n***  key : %d인 record를 삭제, pseudokey : %d ***\n",
               key, makePseudokey(key));
        printTable(dir);
        printf("\n\nPress Enter!!\n");
        scanf("%c", &c);
    }
    fclose(fp);
}

///////////////////////////////////////////////////////
///  key에 해당되는 record를 찾아서 돌려준다.
///////////////////////////////////////////////////////
record* retrieval(int key, directory* dir)
{
    int i;
    int pseudokey = makePseudokey(key);    // pseudokey 생성
    int index = foreget(pseudokey, dir->header);  // entry index
    leaf* bucket = dir->entry[index];
    for (i=0; i<bucket->count; i++)     // 해당 leaf에서 찾고자하는 key를 찾는다.
    {
        record* ptr = dir->entry[index]->pRecord[i];
        if (ptr->key == key)
            return ptr;        // 찾으면 record의 주소를 리턴
    }
    return NULL;         // 없으면 NULL을 리턴
}

///////////////////////////////////////////////////////
///  레코드를 받아서 저장한다.
///////////////////////////////////////////////////////
int insertRecord(record* rec, directory* dir)
{
    int i, ind;
    int key = rec->key;        // 삽입되는 record의 key
    int pseudokey = makePseudokey(key);    // pseudokey
    int index = foreget(pseudokey, dir->header); // entry의 번호를 찾는다.
    leaf* bucket = dir->entry[index];    // 삽입하고자 하는 leaf
    
    
    ////////// 1. bucket을 확인해서 삽입하고자 하는 키가 이미 존재하는지 확인
    for (i=0; i<bucket->count; i++)
    {
        if (bucket->pRecord[i]->key == key)
        {
            printf("\n\nThe key is already exist!!!\n");
            return 0;  // 비정상 종료
        }
    }
    
    ////////// 2. bucket에 저장할 공간이 남아있다면 빈칸에 저장한다.
    if (bucket->count < BUCKET_SIZE)
    {
        bucket->pRecord[bucket->count] = rec;
        bucket->count++;
        return 1;   // 정상종료
    }
    
    
    ////////// 3. bucket이 다 찼다면 overflow 처리
    while (1)
    {
        int n;
        leaf* newBucket;  // 새로 만들 bucket;
        //////  3-1. d < t+1인경우 => 먼저 디렉토리를 두배 늘린다
        if (dir->header < bucket->header+1)
        {
            int numEntry;    // 새로 만들어질 entry의 수
            leaf** newEntry;
            dir->header++;
            numEntry = pow_2(dir->header);
            newEntry = (leaf**)malloc(sizeof(leaf*)*numEntry);
            for (i=0; i<numEntry/2; i++)  // entry를 늘어난 만큼 분배
                newEntry[i*2] = newEntry[i*2+1] = dir->entry[i];
            dir->divCount = 0;
            free(dir->entry);
            dir->entry = newEntry;
        }
        ////// 3-2. 이제 overflow가 생긴 leaf를 split한다.
        // 3-2-1. 새로운 bucket 생성
        newBucket = (leaf*)malloc(sizeof(leaf));
        newBucket->header = bucket->header;
        newBucket->count = 0;
        newBucket->pRecord = (record**)malloc(sizeof(record*) * BUCKET_SIZE);
        
        // 3-2-2. bucket내의 record 분배
        bucket->count = 0;
        for (i=0; i<BUCKET_SIZE; i++)
        {
            if (foreget(makePseudokey(bucket->pRecord[i]->key), bucket->header+1) % 2 == 0)
            {
                bucket->pRecord[bucket->count] = bucket->pRecord[i];
                bucket->count++;
            }
            else
            {
                newBucket->pRecord[newBucket->count] = bucket->pRecord[i];
                newBucket->count++;
            }
        }
        bucket->header++;
        newBucket->header++;
        if (bucket->header == dir->header)
            dir->divCount++;
        
        // 3-2-3. entry -> leaf 로의 pointer 조절
        n = pow_2(dir->header - bucket->header+1);      // 나누어질 entry 수
        ind = foreget(makePseudokey(key), bucket->header-1) * n;   // 나누어질 entry중 첫번째 entry의 index
        
        for (i=0 ; i<n/2; i++, ind++)        // 두개의 bucket으로 나눔
            dir->entry[ind] = bucket;
        for (i=0 ; i<n/2; i++, ind++)
            dir->entry[ind] = newBucket;
        
        // 3-2-4. 이제 다시 삽입될 노드를 저장한다.
        index = foreget(pseudokey, dir->header);
        bucket = dir->entry[index];
        if (bucket->count < BUCKET_SIZE) // 저장할 곳의 bucket이 full이 아니면 저장
        {
            bucket->pRecord[bucket->count] = rec;
            bucket->count++;
            return 1;   // 정상종료
        }
        // 저장할 곳이 full이 아니면 2의 처음으로 돌아가서 다시 directory를 늘린다.
    }
}

///////////////////////////////////////////////////////
///  키를 받아서 해당 레코드를 삭제한다.
///////////////////////////////////////////////////////
int delRecord(int key, directory* dir)
{
    int i, del;
    int pseudokey = makePseudokey(key);
    int index = foreget(pseudokey, dir->header);
    leaf* bucket = dir->entry[index];
    
    //////// 1. bucket에서 삭제하고자 하는 키를 찾음
    for (i=0; i<bucket->count; i++)
        if (bucket->pRecord[i]->key == key)
            break;
    del = i;
    if (i == bucket->count)
    {
        printf("\n\n삭제하려는 키가 존재하지 않습니다. \n");
        return 0;    // 비정상 종료
    }
    
    //////// 2. 삭제할 키를 지우고, bucket을 정렬한다.
    // free(bucket->pRecord[del]);
    for (i=del; i<bucket->count-1; i++)
        bucket->pRecord[i] = bucket->pRecord[i+1];
    bucket->count--;
    //////// 3. buddy bucket과 merge
    while (bucket->header != 2) // leaf의 header는 2보다 작아지지 않는다.
    {
        int i1, i2, buddyIndex, n;
        leaf* buddyBucket;
        //// 3.1 먼저 버디버켓을 찾는다.
        i1 = foreget(pseudokey, bucket->header-1);
        i2 = foreget(pseudokey, bucket->header);
        n = pow_2(dir->header - bucket->header);  // buddy bucket을 가리키는 entry 수
        buddyIndex = (i2+(i1*2==i2?1:-1)) * n;   // buddy bucket을 가르키는 첫 entry의 index
        buddyBucket = dir->entry[buddyIndex];
        //// 3-2 buddy bucket과 현재 bucket의 merge 조건이 맞지 않으면 merge를 끝낸다.
        if (bucket->header != buddyBucket->header || (bucket->count+buddyBucket->count) > BUCKET_SIZE)
            break;
        
        //// 3-3 merge한다. buddyBucket에서 현재bucket으로 record 복사, entry point 관리
        for (i=0; i<buddyBucket->count; i++)   // record를 merge
        {
            bucket->pRecord[bucket->count] = buddyBucket->pRecord[i];
            bucket->count++;
        }
        if (dir->header == bucket->header)
            dir->divCount--;
        bucket->header--;     // header 1 감소
        free(buddyBucket);
        for (i=0; i<n; i++)
            dir->entry[buddyIndex+i] = bucket;
        //// 3-4 directory의 크기를 줄일수 있는지 확인하고 줄인다.
        if (dir->divCount == 0)
        {
            int numEntry;    // 새로 만들어질 entry의 수
            leaf** newEntry;
            dir->header--;
            numEntry = pow_2(dir->header);
            newEntry = (leaf**)malloc(sizeof(leaf*)*numEntry);
            for (i=0; i<numEntry; i++)  // entry를 늘어난 만큼 분배
                newEntry[i] = dir->entry[2*i];
            dir->divCount = 0;
            for (i=0; i<numEntry/2; i++)
                if (newEntry[i*2] != newEntry[i*2+1])
                    dir->divCount++;
            free(dir->entry);
            dir->entry = newEntry;
        }
    }
    return 1;
}

///////////////////////////////////////////////////////
///  hash talbe를 출력한다.
///////////////////////////////////////////////////////
void printTable(directory* dir)
{
    int i, k, j;
    leaf* cBucket;
    leaf* pBucket = NULL;
    for (i=0; i<pow_2(dir->header); i++)
    {
        int c = i;
        for (k=pow_2(dir->header-1); k>0; k/=2)
        {
            printf("%d", c/k);
            c = c%k;
        }
        printf("\t");
        cBucket = dir->entry[i];
        if (cBucket != pBucket)
        {
            printf("%d\t", cBucket->header);
            printf("%d\t", cBucket->count);
            for (j=0; j<cBucket->count; j++)
            {
                printf("%d:", cBucket->pRecord[j]->key);
                printf("%s, ", cBucket->pRecord[j]->name);
            }
        }
        printf("\n");
        pBucket = cBucket;
    }
}



///////////////////////////////////////////////////////
// 간단한 보조함수들
///////////////////////////////////////////////////////
// return 2^p
int pow_2(int p)
{
    int i;
    int x = 1;
    for (i=0; i<p; i++)
        x *= 2;
    return x;
}
//  pseudokey를 만들어서 return 한다.
int makePseudokey(int key)
{
    return key % pow_2(KEY_LENGTH);
}
//  상위 n bit를 돌려준다.
int foreget(int k, int n)
{
    return k / pow_2(KEY_LENGTH - n);
}
e_hashing.txt
Makelele
| 2008.06.13 수정됨 | 의견 1 |신고
추천추천 6   추천자 목록
답변
인터넷에 있던것을 복사해 놓은 것입니다. 참고해서 쓰도록 하세요

/* =======================
 확장성 해싱 구현
 ======================= */
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
/* -------------------------------------
 preprocessor
 ------------------------------------- */
#define PAGE_SIZE 512   /* page size */
#define MAX_D 8     /* max bitstring */
#define POW(x, y) (int) pow(x,y)

/* -------------------------------------
 Record structure
 ------------------------------------- */
struct Record
{
    int key;     /* key field */
    char name[120];  /* name field */
};

/* -------------------------------------
 Bucket Structure
 ------------------------------------- */
struct Bucket
{
    int header;       /* bucket header */
    int recordCnt;      /* bucket 내의 record 개수 */
    struct Record record[4]; /* bucket 내의 record fields */
    char padding[8];    /* page size를 맞추기 위한 padding */
};

/* -------------------------------------
 Directory Structure
 ------------------------------------- */
struct Directory
{
    int header;     /* directory의 header */
    int table[512][3];  /* directory table - index, bucket number, header value*/
};
/* -------------------------------------
 Block Manager Structure
 ------------------------------------- */
struct BlockManager
{
    int blockCnt;   /* Current Block 개수 */
    int blockTable[512]; /* 전체 block의 현재 할당 상황 기록 field */
};
/* -------------------------------------
 global variables
 ------------------------------------- */
FILE* g_pInputStream;  /* input 파일의 핸들 */
FILE* g_pHashStream;  /* Hash 파일의 핸들 */
struct Directory* directory; /* directory */
struct BlockManager  blockManager; /* Block manager */

/* ==========================
 Pseudo key Function
 ========================== */
int PseudoKeyFunc(int key, int digits)
{
    int i;
    int pseudo_key = 0;
    int bit = 0;
    /* key의 뒤 8자리 bit string에서 digits 만큼의 bit string을 얻기 */
    for(i=MAX_D-1; i>=MAX_D-digits; --i)
    {
        bit = (key & POW(2, i) ) > 0 ? 1 : 0;
        pseudo_key += POW(2, i-(MAX_D-digits) )*bit; /* 해당 bit를 누적 */
    }
    return pseudo_key;
}

/* ==========================
 Insert Function
 ========================== */
int Insert(int key, char name[120])
{
    int i, j, k, temp;
    int pseudo_key = 0;  /* 입력 key의 pseudo key*/
    int bucketNum = -1;  /* 할당될 bucket의 number */
    struct Bucket bucket, newBucket; /* disk의 bucket을 가져올 struct */
    struct Record record;
    struct Directory* newDirectory;
    
    /* pseudo_key를 얻어 directory 참조 */
    pseudo_key = PseudoKeyFunc(key, directory->header);
    bucketNum = directory->table[pseudo_key][1];
    /* 얻어온 bucket number를 통해 disk access */
    if(bucketNum >= 0)
    {
        /* 해당 bucket 위치 찾아 읽기 */
        fseek(g_pHashStream, PAGE_SIZE * bucketNum, SEEK_SET);
        j = fread(&bucket, sizeof(struct Bucket), 1, g_pHashStream);
        if(j == 0)
        { /* bucket 존재하지 않음 */
            printf("Error occurred while reading hash file.\n");
            return -1;
        }
        /* 이미 해당 key가 존재하는지 확인 */
        if( bucket.recordCnt > 0)
        {
            for(i=0; i<bucket.recordCnt; ++i)
            {
                if(bucket.record[i].key == key)
                { /* 해당 key 존재 */
                    printf("Insert failed. Key (%d) already exists.\n", key);
                    return 0;
                }
            }
        }
        /* 여유 공간이 있는지 확인 */
        if( bucket.recordCnt < 4 )
        { /* 여유 공간이 있으면 삽입 */
            record.key = key;
            memcpy(record.name, name, 120);
            /*record.name = name;*/
            bucket.record[bucket.recordCnt] = record;
            bucket.recordCnt++;
            /* 바뀐 내용 disk에 쓰기 */
            fseek(g_pHashStream, PAGE_SIZE * bucketNum, SEEK_SET);
            fwrite(&bucket, sizeof(struct Bucket), 1, g_pHashStream);
            /* block manager update */
            blockManager.blockTable[bucketNum] = 1;
            printf("(%d, %s) inserted.\n", key, name);
        }
        else
        { /* bucket에 여유 공간이 없으면 split */
            while(1)
            {
                /* directory를 확장해야 하는지 check */
                if( directory->header < (bucket.header + 1) )
                {
                    /* ----------------------------------------
                     directory 확장
                     ---------------------------------------- */
                    if(directory->header >= MAX_D)
                    { /* 이미 full인지 check */
                        printf("Error. reached the maximum entry.\n");
                        return 0;
                    }
                    /* 새 directory 만들어 카피 */
                    newDirectory = (struct Directory*)malloc(sizeof(struct Directory));
                    memset(newDirectory, 0, sizeof(struct Directory));
                    newDirectory->header = directory->header + 1;
                    for(i=0; i<512; ++i)
                    {
                        newDirectory->table[i][0] = -1;
                        newDirectory->table[i][1] = -1;
                        newDirectory->table[i][2] = 0;
                    }
                    for(i=0; i<POW(2, newDirectory->header); ++i)
                    {
                        newDirectory->table[i][0] = i;
                        newDirectory->table[i][1] = directory->table[i/2][1];
                        newDirectory->table[i][2] = directory->table[i/2][2];
                    }
                    free(directory);
                    directory = newDirectory;
                }
                /* ----------------------------------------
                 overflow가 발생한 bucket을 split
                 ---------------------------------------- */
                /* 새로운 bucket 생성 */
                memset(&newBucket, 0, sizeof(struct Bucket));
                newBucket.header = bucket.header;
                newBucket.recordCnt = 0;
                /* record를 두 bucket에 분배 */
                bucket.recordCnt = 0;
                for(i=0; i<4; ++i)
                {
                    if( PseudoKeyFunc( bucket.record[i].key, bucket.header+1) %2 == 0)
                    { /* 첫번째 bucket */
                        bucket.record[bucket.recordCnt] = bucket.record[i];
                        bucket.recordCnt++;
                    }
                    else
                    { /* 두번째 bucket*/
                        newBucket.record[newBucket.recordCnt] = bucket.record[i];
                        newBucket.recordCnt++;
                    }
                }
                bucket.header++;
                newBucket.header++;
                
                /* disk에 free block이 있는지 확인 */
                temp = -1;
                for(i=0; i< blockManager.blockCnt; ++i)
                {
                    if(blockManager.blockTable[i] == 0) /* free block*/
                    {
                        temp = i;
                        break;
                    }
                }
                if(temp != -1)
                { /* free block 존재 - 해당 block에 write */
                }
                else
                { /* 새로운 block 할당 */
                    temp = blockManager.blockCnt;
                    blockManager.blockCnt++;
                }
                /* 해당 free block에 할당 */
                fseek(g_pHashStream, PAGE_SIZE * temp, SEEK_SET);
                fwrite(&newBucket, sizeof(struct Bucket), 1, g_pHashStream);
                
                blockManager.blockTable[temp] = 1;
                fseek(g_pHashStream, PAGE_SIZE * bucketNum, SEEK_SET);
                fwrite(&bucket, sizeof(struct Bucket), 1, g_pHashStream);
                /* directory의 bucket index 변경 */
                j = POW(2, directory->header - bucket.header + 1);
                k = PseudoKeyFunc(key, bucket.header-1) * j; /* directory의 첫번째 바뀔 부분 index*/
                for(i=0; i<j/2; i++, k++)
                {
                    directory->table[k][1] = bucketNum;
                    directory->table[k][2] = bucket.header;
                }
                for(i=0; i<j/2; i++, k++)
                {
                    directory->table[k][1] = temp;
                    directory->table[k][2] = newBucket.header;
                }
                /* 입력받은 key 삽입 */
                pseudo_key = PseudoKeyFunc(key, directory->header);
                bucketNum = directory->table[pseudo_key][1];
                /* 해당 bucket 위치 찾아 읽기 */
                fseek(g_pHashStream, PAGE_SIZE * bucketNum, SEEK_SET);
                j = fread(&bucket, sizeof(struct Bucket), 1, g_pHashStream);
                if(j == 0)
                { /* bucket 존재하지 않음 */
                    printf("Error occurred while reading hash file.\n");
                    return -1;
                }
                /* ----------------------------------------
                 여유 공간이 있으면 삽입
                 ---------------------------------------- */
                
                /* 여유 공간이 있는지 확인 */
                if( bucket.recordCnt < 4 )
                { /* 여유 공간이 있으면 삽입 */
                    record.key = key;
                    memcpy(record.name, name, 120);
                    /*record.name = name;*/
                    bucket.record[bucket.recordCnt] = record;
                    bucket.recordCnt++;
                    /* 바뀐 내용 disk에 쓰기 */
                    fseek(g_pHashStream, PAGE_SIZE * bucketNum, SEEK_SET);
                    fwrite(&bucket, sizeof(struct Bucket), 1, g_pHashStream);
                    /* block manager update */
                    blockManager.blockTable[bucketNum] = 1;
                    printf("(%d, %s) inserted.\n", key, name);
                    return 0;
                }
                /* 여유 공간이 없는 경우 계속 loop을 돌며 directory 확장 */
            }
        }
    }
    else
    {
        printf("Error occurred while inserting.\n");
        return -1;
    }
    return 0;
}

/* ==========================
 Delete Function
 ========================== */
int Delete(int key)
{
    int i, j, k, temp;
    int b1, b2, cnt;
    int pseudo_key = 0;  /* 삭제될 key의 pseudo key*/
    int bucketNum = -1;  /* bucket의 number */
    struct Bucket bucket, buddyBucket; /* disk에서 bucket과 buddy bucket을 가져올 struct */
    struct Directory* newDirectory;
    
    /* pseudo_key를 얻어 directory 참조 */
    pseudo_key = PseudoKeyFunc(key, directory->header);
    bucketNum = directory->table[pseudo_key][1];
    /* 얻어온 bucket number를 통해 disk access */
    if(bucketNum >= 0)
    {
        /* 해당 bucket 위치 찾아 읽기 */
        fseek(g_pHashStream, PAGE_SIZE * bucketNum, SEEK_SET);
        j = fread(&bucket, sizeof(struct Bucket), 1, g_pHashStream);
        if(j == 0)
        { /* bucket 존재하지 않음 */
            printf("Error occurred while reading hash file.\n");
            return -1;
        }
        /* 해당 key가 존재하는지 확인 */
        temp = -1;
        if( bucket.recordCnt > 0)
        {
            for(i=0; i<bucket.recordCnt; ++i)
            {
                if(bucket.record[i].key == key)
                { /* 해당 key 존재 */
                    temp = i;
                    break;
                }
            }
            if( temp == -1)
            { /* 해당 key 없음 */
                printf("Delete failed. Key (%d) does not exist.\n", key);
                return 0;
            }
        }
        else
        { /* 해당 bucket에 record 없음 */
            printf("Delete failed. Key (%d) does not exist.\n", key);
            return 0;
        }
        /* Bucket에서 key 삭제. bucket 정렬 */
        printf("(%d, %s) deleted\n", bucket.record[temp].key, bucket.record[temp].name);
        for(i=temp; i<bucket.recordCnt-1; ++i)
        {
            bucket.record[i] = bucket.record[i+1];
        }
        bucket.recordCnt--;
        /* disk에 쓰기 */
        fseek(g_pHashStream, PAGE_SIZE * bucketNum, SEEK_SET);
        fwrite(&bucket, sizeof(struct Bucket), 1, g_pHashStream);
        /* bucket이 비거나 merge 가능하면 buddy bucket을 찾아 계속해서 merge */
        while(bucket.header >= 2)
        {
            /* buddy bucket 찾기 */
            b1 = PseudoKeyFunc(key, bucket.header -1);
            b2 = PseudoKeyFunc(key, bucket.header);
            cnt = POW(2, directory->header - bucket.header); /* 연관된 leaf의 개수 */
            k = (b2 + (b1*2 == b2 ? 1 : -1) ) * cnt;  /* 연관된 leaf 중 첫번째 leaf index */
            temp = directory->table[k][1];
            if(temp < 0)
            {
                return 0;
            }
            /* disk에서 buddy bucket 읽어 오기 */
            memset(&buddyBucket, 0, sizeof(struct Bucket));
            fseek(g_pHashStream, PAGE_SIZE * temp, SEEK_SET);
            j = fread(&buddyBucket, sizeof(struct Bucket), 1, g_pHashStream);
            if(j == 0)
            { /* bucket 존재하지 않음 */
                printf("Error occurred while reading hash file.\n");
                return -1;
            }
            /* merge 해야 하는지 check */
            if( (bucket.header != buddyBucket.header) ||
               (bucket.recordCnt + buddyBucket.recordCnt > 4) )
            { /* merge될 필요 없음 */
                break;
            }
            /* ----------------------------------------
             merge
             ---------------------------------------- */
            /* buddyBucket에서 bucket으로 record copy */
            for(i=0; i<buddyBucket.recordCnt; ++i)
            {
                bucket.record[bucket.recordCnt] = buddyBucket.record[i];
                bucket.recordCnt++;
            }
            bucket.header--;
            fseek(g_pHashStream, PAGE_SIZE * bucketNum, SEEK_SET);
            fwrite(&bucket, sizeof(struct Bucket), 1, g_pHashStream);
            /* directory에서 leaf 조정 */
            directory->table[pseudo_key][2] = bucket.header;
            for(i=0; i<cnt; ++i)
            { /* buddy 변경 */
                directory->table[k + i][1] = bucketNum;
                directory->table[k + i][2] = bucket.header;
            }
            /* buddyBucket 제거 */
            /*blockManager.blockCnt--;*/
            blockManager.blockTable[temp] = 0; /* free blcok으로 set */
            memset(&buddyBucket, 0, sizeof(struct Bucket));
            fseek(g_pHashStream, PAGE_SIZE * temp, SEEK_SET);
            fwrite(&buddyBucket, sizeof(struct Bucket), 1, g_pHashStream);
            
            /* directory가 줄어들 수 있는지 확인 */
            j = 0;
            for(i=0; i<POW(2, directory->header); ++i)
            {
                if( directory->table[i][2] >= directory->header )
                {
                    j = 1;
                    break;
                }
            }
            if(j == 0 )
            { /* bucket의 모든 header 값이 directory header 값보다 작은 경우 */
                /* ----------------------------------------
                 directory 축소
                 ---------------------------------------- */
                newDirectory = (struct Directory*)malloc(sizeof(struct Directory));
                memset(newDirectory, 0, sizeof(struct Directory));
                newDirectory->header = directory->header - 1;
                for(i=0; i<512; ++i)
                {
                    newDirectory->table[i][0] = -1;
                    newDirectory->table[i][1] = -1;
                    newDirectory->table[i][2] = 0;
                }
                for(i=0; i<POW(2, newDirectory->header); ++i)
                {
                    newDirectory->table[i][0] = i;
                    newDirectory->table[i][1] = directory->table[i*2][1];
                    newDirectory->table[i][2] = directory->table[i*2][2];
                }
                free(directory);
                directory = newDirectory;
            }
        }
    }
    else
    {
        printf("Error occurred while deleting.\n");
        return -1;
    }
    return 0;
}

/* ==========================
 Retrieve Function
 ========================== */
int Retrieve(int key)
{
    int i, j, temp;
    int pseudo_key = 0;  /* 삭제될 key의 pseudo key*/
    int bucketNum = -1;  /* bucket의 number */
    struct Bucket bucket; /* disk에서 bucket을 가져올 struct */
    
    /* pseudo_key를 얻어 directory 참조 */
    pseudo_key = PseudoKeyFunc(key, directory->header);
    bucketNum = directory->table[pseudo_key][1];
    /* 얻어온 bucket number를 통해 disk access */
    if(bucketNum >= 0)
    {
        /* 해당 bucket 위치 찾아 읽기 */
        fseek(g_pHashStream, PAGE_SIZE * bucketNum, SEEK_SET);
        j = fread(&bucket, sizeof(struct Bucket), 1, g_pHashStream);
        if(j == 0)
        { /* bucket 존재하지 않음 */
            printf("Error occurred while reading hash file.\n");
            return -1;
        }
        /* 해당 key가 존재하는지 확인 */
        temp = -1;
        if( bucket.recordCnt > 0)
        {
            for(i=0; i<bucket.recordCnt; ++i)
            {
                if(bucket.record[i].key == key)
                { /* 해당 key 존재 */
                    temp = i;
                    printf("(%d, %s) found\n", bucket.record[temp].key, bucket.record[temp].name);
                    break;
                }
            }
            if( temp == -1)
            { /* 해당 key 없음 */
                printf("Search failed. Key (%d) was not found.\n", key);
                return 0;
            }   
        }
        else
        { /* 해당 bucket에 record 없음 */
            printf("Search failed. Key (%d) was not found.\n", key);
            return 0;
        }
    }
    else
    {
        printf("Error occurred while searching.\n");
        return -1;
    }
    return 0;
}

/* ==========================
 Print Hash state Function
 ========================== */
void PrintHash()
{
    int i, j;
    int prevBucket = -1;
    struct Bucket bucket;
    char bitStr[10];
    printf("======================================================================\n");
    printf("Directory (%d)         Hash State \n", directory->header);
    printf("======================================================================\n");
    for(i=0; i<POW(2, directory->header); ++i)
    {
        /* ----------------------------------------
         bit string 생성
         ---------------------------------------- */
        for(j=0; j<directory->header; ++j)
        {
            bitStr[j] = (directory->table[i][0] & POW(2,directory->header - j-1) ) > 0 ? '1' : '0';   
        }
        bitStr[directory->header] = '\0';
        /* ----------------------------------------
         directory 내용 출력
         ---------------------------------------- */
        printf("[%s] [B: %d]", bitStr, directory->table[i][1] );
        if( directory->table[i][1] != prevBucket)
        {
            prevBucket = directory->table[i][1];
            /* ----------------------------------------
             해당 bucket 내용 출력 
             ---------------------------------------- */
            fseek(g_pHashStream, PAGE_SIZE * prevBucket, SEEK_SET);
            j = fread(&bucket, sizeof(struct Bucket), 1, g_pHashStream);
            if(j == 0)
            { /* bucket 존재하지 않음 */
                printf("Error occurred while reading hash file.\n");
                return;
            }
            printf("\t[B: %d](%d)  ", prevBucket, bucket.header);
            for(j=0; j<bucket.recordCnt; ++j)
            {   
                printf("(%d, %s)  ", bucket.record[j].key, bucket.record[j].name);
            }
        }
        printf("\n");
    }
    printf("\n"); 
}

/* ==========================
 main
 ========================== */
int main(int argc, char* argv[])
{
    int i, key;
    char c;
    char name[120];
    struct Bucket bucket;
    
    /* -------------------------------------
     Directory 초기화
     ------------------------------------- */ 
    directory = (struct Directory*)malloc(sizeof(struct Directory));
    memset(directory, 0, sizeof(struct Directory));
    directory->header = 0;
    for(i=0; i<512; ++i)
    {
        directory->table[i][0] = -1;
        directory->table[i][1] = -1;
        directory->table[i][2] = 0;
    }
    /* directory에 초기 table 생성 */
    directory->header = 2;
    for(i=0; i<4; ++i)
    {
        directory->table[i][0] = i; /*bit string */
        directory->table[i][1] = 0;  /* bucket number는 0 */
        directory->table[i][1] = 0;
    }
    /* -------------------------------------
     Block manager 초기화
     ------------------------------------- */ 
    blockManager.blockCnt = 0;
    for(i=0; i<512; ++i)
    {
        blockManager.blockTable[i] = 0;
    }
    
    /* -------------------------------------
     File 열기
     ------------------------------------- */
    /* input.txt 파일 열기 */
    if( (g_pInputStream = fopen("input.txt", "r")) == NULL )
    {
        /* input 파일을 열 수 없음 */
        printf("input.txt file cannot be opened!\n");
        return -1;
    }
    /* hash.txt 파일 열기 */
    if( (g_pHashStream = fopen("hash.txt", "w+")) == NULL ) /* overwrite */
    {
        /* hash 파일을 열 수 없음 */
        printf("hash.txt file cannot be opened!\n");
        return -1;
    }
    /* 초기 bucket 생성 */
    blockManager.blockCnt = 4;
    
    memset(&bucket, 0, sizeof(struct Bucket));
    bucket.header = 0;
    bucket.recordCnt = 0;
    for(i=0; i<4; ++i)
    {
        fwrite(&bucket, sizeof(struct Bucket), 1, g_pHashStream);
    }
    
    /* -------------------------------------
     input file을 읽어 명령 수행
     ------------------------------------- */
    printf("[Extendible Hashing] Started\n\n");
    while(1)
    {
        if( fscanf(g_pInputStream, "%c", &c) == EOF)
        { /* EOF에 도달 */
            break;
        }
        switch( c )
        {
            case 'I':
            case 'i': /* insert */
                if( fscanf(g_pInputStream, "%d %s", &key, name) == EOF )
                {
                    printf("Error occurred. Input file corrupted.\n");
                    return -1;
                }
                if( Insert(key, name) == 0)
                {
                    PrintHash();
                }
                break;
            case 'D':
            case 'd': /* delete */
                if( fscanf(g_pInputStream, "%d", &key) == EOF )
                {
                    printf("Error occurred. Input file corrupted.\n");
                    return -1;
                }
                if( Delete(key) == 0)
                {
                    PrintHash();
                }
                break;
            case 'R':
            case 'r': /* retrieve */
                if( fscanf(g_pInputStream, "%d", &key) == EOF )
                {
                    printf("Error occurred. Input file corrupted.\n");
                    return -1;
                }
                if( Retrieve(key) == 0)
                {
                    PrintHash();
                }
                break;
            default:
                break;
        } 
    }
    /* -------------------------------------
     종료
     ------------------------------------- */
    fclose(g_pInputStream);
    fclose(g_pHashStream);
    printf("\n[Extendible Hashing] Ended\n\n");
    
    return 0;
}
