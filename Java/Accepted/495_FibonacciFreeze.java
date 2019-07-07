import java.io.*;
import java.math.BigInteger;

class Main{
	public static BigInteger[] memo = new BigInteger[5010];
	public static int visit[] = new int[5010];
	public static BigInteger fibo(int n) {
		if ( n < 4) return memo[n];
		else if ((visit[n - 1] != -1) && (visit[n-2] != -1)) return memo[n-1].add(memo[n-2]);
		BigInteger a = fibo(n - 1);
		BigInteger b = fibo(n - 2);
		memo[n] = a.add(b);
		visit[n] = 1;
		return memo[n];
	}
	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		String str = "";
		int num;
		memo[0] = new BigInteger("0"); visit[0] = 1;
		memo[1] = new BigInteger("1"); visit[1] = 1;
		memo[2] = new BigInteger("1"); visit[2] = 1;
		memo[3] = new BigInteger("2"); visit[3] = 1;
		for(int i = 3; i < 5010; i++)
			visit[i] = -1;
		while((str = reader.readLine()) != null && str.length()>0) {
			num = Integer.parseInt(str);
			System.out.println("The Fibonacci number for " + num + " is " + fibo(num));
		}
	}
}