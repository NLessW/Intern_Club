const mostWordsFound = sentences => sentences.reduce((max, sentence) => Math.max(max, sentence.split(" ").length), 0);
