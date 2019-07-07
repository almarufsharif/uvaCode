import java.io.*;
import java.math.BigInteger;
class Main {
	public static void main(String[] args) throws IOException {
		String str = "";
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		
		while((str = reader.readLine()) !=null && str.length()>0) {
			String []splits = str.split("\\s+");
			BigInteger num1 = new BigInteger(splits[0].trim());
			String operation = splits[1].trim();
			BigInteger num2 = new BigInteger(splits[2].trim());
			
			if(operation.equals("/"))
				System.out.println(num1.divide(num2));
			else if (operation.equals("%"))
				System.out.println(num1.mod(num2));
		}
	}
}