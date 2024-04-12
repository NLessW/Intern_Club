class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWords = 0;
        for(const string& sentence : sentences){
            int count = 0;
            size_t pos = 0;

            while ((pos = sentence.find(' ',pos))!=string::npos){
                count++;
                pos++;
            }
            count++;
            maxWords = max(maxWords, count);
        }
        return maxWords;
    }
};
