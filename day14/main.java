package day14;

import java.io.*;
import java.util.Arrays;

public class main {
	public static void main(String[] args) {
		String fileName = "input.txt";
		String line = null;

		try {
			FileReader fileReader = new FileReader(fileName);
			BufferedReader bufferedReader = new BufferedReader(fileReader);
			String delims = " ";
			String[] part = null;
			Reindeer a = null;
			Database x = new Database();
			while ((line = bufferedReader.readLine()) != null) {
				part = line.split(delims);
				a = new Reindeer(part[0], part[3], part[6], part[13]);
				
				x.add(a);
				/*
				 * Part1: x.max(a.calculate()); System.out.println(x.getMax());
				 *  x.record(a.getName(), a.calculate()); // record and store
				 * info of reindeer
				 */
			}
			for (int k = 1; k <= 2503; k++) {
				for (int h = 0; h < 9; h++) {
					x.getInfo(h).calculatePerSecond(k);
					x.comparedistance(x.getInfo(h).getTempDistance());
				}
				for (int h = 0; h < 9; h++) {
					if (x.getInfo(h).getTempDistance() == x.getcurrentmaxDistance()) {
						x.getInfo(h).addPoint();
					}
				}
				// a.getReindeer(x.getcurrentmaxDistance());
				// System.out.println(a.getPoint());
			}
			for (int h = 0; h < 9; h++) {
				x.comparepoint(x.getInfo(h).getPoint());
			}
			System.out.println(x.returnPoint());
			bufferedReader.close();
		} catch (FileNotFoundException ex) {
			System.out.print("Unable to open file");
		} catch (IOException ex) {
			System.out.println("Error reading file '" + fileName + "'");
			// Or we could just do this:
			// ex.printStackTrace();
		}
	}
}
