// leetcode 119
// Pascal's Triangle II

class Solution {
public
  List<Integer> getRow(int rowIndex) {
    List<List<Integer>> triangle = new ArrayList<List<Integer>>();

    triangle.add(new ArrayList<Integer>());
    triangle.get(0).add(1); // initialize

    // condtruct each row base on prev row
    for (int i = 1; i < rowIndex + 1; i++) {
      List<Integer> row = new ArrayList<>();
      List<Integer> prevRow = triangle.get(i - 1);

      row.add(1);

      for (int j = 1; j < i; j++) {
        row.add(prevRow.get(j) + prevRow.get(j - 1));
      }

      row.add(1);
      triangle.add(row);
    }
    return triangle.get(rowIndex);
  }
}