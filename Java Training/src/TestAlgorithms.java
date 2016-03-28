import static org.junit.Assert.*;

import org.junit.Test;

public class TestAlgorithms {
	int[] theArray = new int[] {4, 2, 6, 1, 7, 3, 8, 5};
	
	@Test
	public void TestLinearSearch() {
		int result = Algorithms.IndexOf(theArray, 2);
		assertEquals(1, result);
	}
	
	@Test
	public void TestLinearSearchFail() {
		int result = Algorithms.IndexOf(theArray, 9);
		assertEquals(-1, result);
	}
}
