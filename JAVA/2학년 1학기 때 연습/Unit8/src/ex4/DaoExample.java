package ex4;

public class DaoExample {
	public static void dbWork(DataAccessObject dao){
		dao.select();
		dao.insert();
		dao.update();
		dao.delete();
	}
	
	public static void mainOfEx4(String[] args){
		dbWork(new OracleDao());
		dbWork(new MySqlDao());
	}
}
