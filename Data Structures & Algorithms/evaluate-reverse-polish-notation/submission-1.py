class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        operators = ["+", "-", "*", "/"]
        stack = []

        for n in tokens:
            if n in operators:
                b = stack.pop()
                a = stack.pop()

                if n == "+":
                    stack.append(a + b)
                elif n == "-":
                    stack.append(a - b)
                elif n == "*":
                    stack.append(a * b)
                elif n == "/":
                    stack.append(int(float(a) / b))  
            else:
                stack.append(int(n))

        return(stack[0])
        