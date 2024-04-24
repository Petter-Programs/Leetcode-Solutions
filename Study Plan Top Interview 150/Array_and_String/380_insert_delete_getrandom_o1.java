class RandomizedSet {

    HashMap<Integer, Integer> hashMap;
    ArrayList<Integer> history;

    public RandomizedSet() {
        hashMap = new HashMap<Integer, Integer>();
        history = new ArrayList<Integer>();
    }
    
    public boolean insert(int val) 
    {
        if(hashMap.containsKey(val))
            return false;

        history.add(val);
        hashMap.put(val, history.size()-1);

        return true;
    }
    
    public boolean remove(int val) {
        
        if(!hashMap.containsKey(val))
            return false;
        
        int indexInHistory = hashMap.get(val);
        int lastElement = history.size()-1;

        if(indexInHistory!=lastElement)
        {
            int last = history.get(lastElement);

            history.set(indexInHistory, last);
            hashMap.replace(last, indexInHistory);
        }

        history.remove(lastElement);
        hashMap.remove(val);

        return true;
    }
    
    public int getRandom() 
    {
        Random rand = new Random();
        int n = rand.nextInt(history.size());
        return history.get(n);
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */