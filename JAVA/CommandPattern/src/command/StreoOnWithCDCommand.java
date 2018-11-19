package command;

import thing.Streo;

public class StreoOnWithCDCommand implements Command{
	Streo streo;

	public StreoOnWithCDCommand(Streo streo){
		this.streo = streo;
	}
	
	@Override
	public void execute() {
		// TODO Auto-generated method stub
		streo.on();
		streo.setCd();
		streo.setVolume();
	}
}
