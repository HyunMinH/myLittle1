#include <stdio.h>




int main(void){
    void *p;
    char string[][20] = {{"C 언어, "},{"재밌어요! \n"}, {"힘 내!!"}, {"경화야 \n"}};
    
    p = string;
    
    printf("%s%s", p, p+1);
    
}
