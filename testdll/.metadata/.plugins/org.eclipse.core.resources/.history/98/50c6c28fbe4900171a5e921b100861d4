package test;

import com.utry.javaCallDLL.AlgorithmDLL;

public class CallDll {

	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		AlgorithmDLL ad = new AlgorithmDLL();
		String platePath = "7.jpg";		
		String testImagePath = "3.jpg";
		String normalImagePath = "";
		//System.out.println(platePath);
		System.out.println("车牌识别结果："+ ad.LPR(platePath));
		System.out.println("火灾识别结果："+ ad.FR(100,platePath,testImagePath,normalImagePath));
		System.out.println("照明灯异常识别结果："+ ad.LR(testImagePath,normalImagePath));
		System.out.println("窨井盖异常识别结果："+ ad.SCR(testImagePath,normalImagePath));
		//System.out.println("楼道门异常识别结果："+ ad.DR(doorImagePath,normalImagePath));
	}

}
