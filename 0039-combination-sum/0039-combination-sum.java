class Solution {
    //store the final ans list.
    public List<List<Integer>> ans = new ArrayList<>();

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        // creating a empty list..
        List<Integer> list = new ArrayList<>();

        findCombination(list, candidates, target, 0, 0);
        return ans;
    }

    public void findCombination(List<Integer> list, int[] candidats, int target, int sum, int index){
        //Base conditon
        if(sum == target){
            ans.add(new ArrayList<>(list));
            return;
        }
        if(sum > target){
            return;
        }

        for(int i = index; i < candidats.length; i++){
            // sum += candidats[i];
            list.add(candidats[i]);

            findCombination(list, candidats, target, sum + candidats[i], i);

            //backtrack
            // sum -= candidats[i];
            list.remove(list.size()-1);
        }
    }
}