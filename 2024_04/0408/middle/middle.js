function solution(numbers) {
    return numbers.reduce((answer, num, idx) => {
        numbers.slice(idx + 1).forEach((n) => {
            const sum = num + n;
            if (!answer.includes(sum)) answer.push(sum);
        });
        return answer;
    }, []).sort((a, b) => a - b);
}
