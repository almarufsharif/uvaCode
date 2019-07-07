import java.io.*;
class Main{
	public static void main(String[] args) throws IOException {
		String line;
		long startTime = 0, endTime = 0, elapsedTime = 0;
		long hour, min, sec, speed=0;
		double totalTime = 0.0;
		boolean f = false;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		while((line = reader.readLine()) != null) {
			String arr[] = line.split("[: ]");
			hour = Long.parseLong(arr[0]);
			min = Long.parseLong(arr[1]);
			sec = Long.parseLong(arr[2]);
			if(!f) {
				if(arr.length == 4)	speed = Long.parseLong(arr[3]);
				else speed = 0;
				startTime = hour * 60 * 60;
				startTime += min * 60;
				startTime += sec;
				f = true;
			}
			else {
				endTime = hour * 60 * 60;
				endTime += min * 60;
				endTime += sec;
				elapsedTime = endTime - startTime;
				startTime = endTime;
				double d = (speed * elapsedTime)/3600.0;
				totalTime += d;
			}
			
			if(arr.length == 3) {
				System.out.print(arr[0]+":"+arr[1]+":"+arr[2]+ " ");
				System.out.printf("%.2f km\n", totalTime);
			}
			if(arr.length == 4)
				speed = Integer.parseInt(arr[3]);
		}
	}
}