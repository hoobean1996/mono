// leetcode 118
// Pascal's Triangle

class Solution {
public
  List<List<Integer>> generate(int numRows) {
    List<List<Integer>> triangle = new ArrayList<List<Integer>>();

    // initialize
    triangle.add(new ArrayList<>());
    triangle.get(0).add(1);

    // construct each line based on previous row

    for (int i = 1; i < numRows; i++) {
      List<Integer> row = new ArrayList<Integer>();
      List<Integer> preRow = triangle.get(i - 1);

      row.add(1);

      for (int j = 1; j < i; j++) {
        row.add(preRow.get(j) + preRow.get(j - 1));
      }

      row.add(1);
      triangle.add(row);
    }
    return triangle;
  }
}