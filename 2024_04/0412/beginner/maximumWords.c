int mostWordsFound(char** sentences, int sentencesSize) {
    int maxWords = 0;

    for(int i = 0; i < sentencesSize; i++){
        int count = 0;
        char *sentence = sentences[i];

        for(int j=0; j<strlen(sentence); j++){
            if (sentence[j] == ' '){
                count++;
            }
        }
        count++;
        if(count>maxWords){
            maxWords = count;
        }
    }
    return maxWords;
}
