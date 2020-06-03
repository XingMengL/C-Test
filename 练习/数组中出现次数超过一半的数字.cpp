class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    
        int len = numbers.size();
        
        int flage = 0;
        int countArray[10] ={0};
        for(int i = 0; i < len; i++)
        {
            countArray[numbers[i]]++;
        }
        for(int i = 0; i < 10; i++)
        {
            if(countArray[i] > len/2)
             flage = i;
        }
        return flage;
    }
};
