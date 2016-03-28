
public class Algorithms {
	// Linear search algorithm
	static int IndexOf(int[] theArray, int targetValue) {
		for (int index = 0; index < theArray.length; ++index)
		{
			if (theArray[index] == targetValue)
				return index;
		}
		return -1;
	}
	
	public static void main(String[] args) {
		int[] theArray = new int[] {4, 2, 6, 1, 7, 3, 8, 5};
		int value1 = 4;
		int result = IndexOf(theArray, value1);
		System.out.println("Looking for the value " + value1 + " in the array.");
		if (result != -1)
			System.out.println("Value found");
		else
			System.out.println("Value not found");
	}
}
