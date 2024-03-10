class Solution:
    def calculate(self, s: str) -> int:
        output, i = self.evaluate(s + "+", 0)
        return output

    def evaluate(self, s, i):
        output = 0
        num = 0
        prev_op = "+"
        prev = 0
        while i < len(s):
            char = s[i]
            if char.isdigit():
                num = num * 10 + int(char)
            elif char == "(":
                num, i = self.evaluate(s, i+1)
            # we do the calculation when we have {'+', '-', '*', '/', ")"}
            elif char in {'+', '-', '*', '/', ")"}:
                if prev_op == "+":
                    output += num
                    prev = num
                elif prev_op == "-":
                    output -= num
                    prev = -num
                elif prev_op == "*":
                    output -= prev
                    output += prev * num
                    prev = prev * num
                elif prev_op == "/":
                    output -= prev
                    output += int(prev / num)
                    prev = int(prev / num)
                if char != ")":
                    prev_op = char
                    num = 0
                else:
                    return output, i
            i += 1
        return output, i