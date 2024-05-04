import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args){
		String fileName = "input.txt";
		int count = 0;
		int[] array;
		try {
			Scanner inputFile = new Scanner(new File(fileName));
			while(inputFile.hasNext()){
				count++;
				inputFile.nextLine();
			}//while
			inputFile.close();
			array = new int[count];
			inputFile = new Scanner(new File(fileName));
			int i = 0;
			while(inputFile.hasNext()){
				array[i++] = inputFile.nextInt();
			}//while
			inputFile.close();
		} catch (FileNotFoundException e){
			System.out.println("Input file " +
					fileName +
					" is not found");
			return;
		}//try catch
		printArray(array);
		getSum(array);
		getHighest(array);
		getLowest(array);
		getAverage(array);
	}//main()
	public static void printArray(int[] arr){
		for (int i = 0; i < arr.length; i++){
			System.out.println("" + i + ": " + arr[i]);
		}
	}//printArray
	public static void getLowest(int[] arr){
		int[] array;
		array = new int [arr.length];
		for (int i = 0; i < array.length; i++){
			array[i] = arr[i];
		}
		int lowest = array[0];
		for (int i = 1; i < array.length; i++){
			if (array[i] < lowest)
				lowest = array[i];
		}
		System.out.println("The Lowest is: " + lowest);
	}//getLowest
	public static void getAverage(int[] arr){
		int[] array;
		double average;
		array = new int [arr.length];
		for (int i = 0; i < array.length; i++){
			array[i] = arr[i];
		}
		int total = 0;
		for (int i = 0; i < array.length; i++){
			array[i] = arr[i];
			total += array[i];
		}
		average = (total) / (array.length);
		System.out.println("The Average is: " + average);
	}//getAverage
	public static void getSum(int[] arr){
		int[] array;
		array = new int[arr.length];
		int total = 0;
		for (int i = 0; i < array.length; i++){
			array[i] = arr[i];
			total += array[i];
		}
		System.out.println("\nThe Total is: " + total);
	}//getSum
	public static void getHighest(int[] arr){
		int[] array;
		array = new int [arr.length];
		for (int i = 0; i < array.length; i++){
			array[i] = arr[i];
		}
		int highest = array[0];
		for (int i = 1; i < array.length; i++){
			if (array[i] > highest)
				highest = array[i];
		}
		System.out.println("The Highest is: " + highest);
	}//getHighest
}//class Main
