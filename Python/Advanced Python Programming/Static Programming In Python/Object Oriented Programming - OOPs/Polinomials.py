class New_Type(type):
    def __repr__(self) -> str:
        return self.__name__

class Polinomials(metaclass = New_Type):
    # Defining Errors...
    exponentialConstant = "Invalid Polinomial! : Adding Exponent To Constant Is Not A Valid Polinomial Syntax!!!"
    
    # Defining Some Dunder/Magic/Special Methods(Functions)...
    def __init__(self, polinomial : str = "x + y + 1") -> None:
        self.polinomial = polinomial
        self.variables, self.constants, self.exponents, self.monomials = Polinomials.compile_Polinomial(polinomial)

    def __repr__(self) -> str:
        if len(self.variables) == 1 and self.variables[0] is None:
            string = "< Constant Object Belonging To Class Polinomial."
        elif len(self.variables) == 1:
            string = "< Monomial Object Belonging To Class Polinomial."
        elif len(self.variables) == 2:
            string = "< Binomial Object Belonging To Class Polinomial."
        elif len(self.variables) == 3:
            string = "< Trinomial Object Belonging To Class Polinomial."
        else:
            string = f"< Polinomial Object With {len(self.variables)} Terms."

        return string + f" Expresion: {self.polinomial} >"

    def __str__(self) -> str:
        return str(self.polinomial)

    def __call__(self):
        print("\nExtracting Data From The Polinomial Object...\n")
        for index in range(len(self.variables)):
            print(f"< [Term No. {index + 1} : {self.monomials[index]}] Variable: {self.variables[index]} | Constant: {self.constants[index]} | Exponent: {self.exponents[index]} >")
        print("\nPolinomial Object Data Extraction Complete.\n")

    def __add__(self, other: object):
        string = ""
        if len(self.variables) >= len(other.variables):
            for index in range(len(self.variables)):
                temp = string
                for monomial in range(len(other.variables)):
                    if self.variables[index] == other.variables[monomial] and self.exponents[index] == other.exponents[monomial]:
                        # print(f"Variable Matched: {self.variables[index]} | {self.constants[index]} + {other.constants[monomial]} = {self.constants[index] + other.constants[monomial]}")
                        if self.variables[index] != None:
                            if self.constants[index] + other.constants[monomial] < 0:
                                string += f"{self.constants[index] + other.constants[monomial]}{self.variables[index]} "
                            else:
                                string += f"+ {self.constants[index] + other.constants[monomial]}{self.variables[index]} "
                        else:
                            if self.constants[index] + other.constants[monomial] < 0:
                                string += f"{self.constants[index] + other.constants[monomial]} "
                            else:
                                string += f"+ {self.constants[index] + other.constants[monomial]} "


                if temp == string:
                    if self.constants[index] + other.constants[monomial] < 0:
                        if self.variables[index] != None:
                            string += f"{self.constants[index]}{self.variables[index]} "
                        else:
                            string += f"{self.constants[index]} "
                    else:
                        if self.variables[index] != None:
                            string += f"+ {self.constants[index]}{self.variables[index]} "
                        else:
                            string += f"+ {self.constants[index]} "
        else:
            for index in range(len(other.variables)):
                temp = string
                for monomial in range(len(self.variables)):
                    if other.variables[index] == self.variables[monomial] and other.exponents[index] == self.exponents[monomial]:
                        if other.variables[index] != None:
                            if self.constants[index] + other.constants[monomial] < 0:
                                string += f"{self.constants[index] + other.constants[monomial]}{other.variables[index]} "
                            else:
                                string += f"+ {self.constants[index] + other.constants[monomial]}{other.variables[index]} "
                        else:
                            if self.constants[index] + other.constants[monomial] < 0:
                                string += f"{self.constants[index] + other.constants[monomial]} "
                            else:
                                string += f"+ {self.constants[index] + other.constants[monomial]} "
                            
                if temp == string:
                    if index < len(self.constants):    
                        if other.variables[index] != None:
                            if self.constants[index] + other.constants[monomial] < 0:
                                string += f"{other.constants[index]}{other.variables[index]} "
                        else:
                            string += f"{other.constants[index]} "
                    else:
                        if other.variables[index] != None:
                            string += f"+ {other.constants[index]}{other.variables[index]} "
                        else:
                            string += f"+ {other.constants[index]} "

        if string[0] == '+':
            string = string[2: ]  

        return string

    def __sub__(self, other: object):
        string = ""
        if len(self.variables) >= len(other.variables):
            for index in range(len(self.variables)):
                temp = string
                for monomial in range(len(other.variables)):
                    if self.variables[index] == other.variables[monomial] and self.exponents[index] == other.exponents[monomial]:
                        # print(f"Variable Matched: {self.variables[index]} | {self.constants[index]} + {other.constants[monomial]} = {self.constants[index] + other.constants[monomial]}")
                        if self.constants[index] + other.constants[monomial] < 0:
                            string += f"{self.constants[index] - other.constants[monomial]}{self.variables[index]} "
                        else:
                            string += f"+{self.constants[index] - other.constants[monomial]}{self.variables[index]} "

                if temp == string:
                    if self.constants[index] + other.constants[monomial] < 0:
                        string += f"{self.constants[index]}{self.variables[index]} "
                    else:
                        string += f"+{self.constants[index]}{self.variables[index]} "
        else:
            for index in range(len(other.variables)):
                temp = string
                for monomial in range(len(self.variables)):
                    if other.variables[index] == self.variables[monomial] and other.exponents[index] == self.exponents[monomial]:
                        if self.constants[index] + other.constants[monomial] < 0:
                            string += f"{self.constants[index] - other.constants[monomial]}{other.variables[index]} "
                        else:
                            string += f"+{self.constants[index] - other.constants[monomial]}{other.variables[index]} "
                            
                if temp == string:
                    if index < len(self.constants):
                        if self.constants[index] + other.constants[monomial] < 0:
                            string += f"{other.constants[index]}{other.variables[index]} "
                    else:
                        string += f"+{other.constants[index]}{other.variables[index]} "

        if string[0] == '+':
            string = string[1: ]  
        for i in range(len(string) - 1):
            if string[i] == '+' and string[i + 1] == '-':
                string = string[ :i] + string[i+1: ]

        return string

    def __eq__(self, other: object) -> bool:
        if str(self.polinomial) == str(other.polinomial):
            return True
        if len(self.variables) != len(other.variables):
            return False
        else:
            for index in range(len(self.variables)):
                value = False
                for dex in range(len(other.variables)):
                    if self.variables[index] == other.variables[dex]:
                        if self.constants[index] == other.constants[dex]:
                            if self.exponents[index] == other.exponents[dex]:
                                value = True
                                break
                if not value:
                    return False
            return True


    # Defining Some Static Methods...
    @staticmethod
    def compile_Polinomial(polinomial : str) -> list:
        exponents = {}
        variables = {}
        constants = {}

        polinomial1 = polinomial.replace(' ', '')
        l = polinomial1.split('+') 
        l1 = []

        for item in l:
            num = item.count('-')
            if num == 0:
                l1.append(item)

            elif num == 1:
                if item[0] == '-':
                    l1.append(item)
                else:
                    temp = item.split('-')
                    l1.append(temp[0])
                    l1.append(f'-{temp[1]}')
            else:
                temp = item.split('-')
                l1.append(temp[0])
                for i in range(1, (num + 1)):
                    # print(i)
                    l1.append(f'-{temp[i]}')
        if '' in l1:
            l1.remove('')
            
        for index in range(len(l1)):
            string : str = l1[index]
            # print(string.islower())
            if Polinomials.is_Variable(string):

                if '^' in string:
                    exponent = string.find('^')
                    exponents[index] = int(string[exponent + 1])
                    variables[index] = string[exponent - 1]
                    constants[index] = int(string.split(string[exponent - 1])[0])

                elif len(string) >= 2:
                    variable = len(string) - 1
                    exponents[index] = 1
                    variables[index] = string[variable]
                    constants[index] = int(string.split(string[variable])[0])

                else:
                    exponents[index] = 1
                    variables[index] = string[0]
                    constants[index] = 1

            else:

                if '^' in string: 
                    raise Exception(Polinomials.exponentialConstant)
                exponents[index] = 1 
                variables[index] = None
                constants[index] = int(string)
        
        # print(f"Exponents:- {exponents}")
        # print(f"Variables:- {variables}")
        # print(f"Constants:- {constants}")
        # print(polinomial)
        return [variables, constants, exponents, l1]

    @staticmethod
    def is_Variable(monomial : str) -> bool:
        import string
        leagal_Variables = list(string.ascii_lowercase)
        for variable in leagal_Variables:
            if variable in monomial:
                return True
        return False

    # Defining Some Class Methods...


class Equations(metaclass = New_Type):

    def __init__(self, equation: str) -> None:
        self.equation = equation
        self.LHS, self.RHS = equation.split('=')
        self.Left_Polinomial = Polinomials(self.LHS)
        self.Right_Polinomial = Polinomials(self.RHS)
        print(self.Left_Polinomial)
        print(self.Right_Polinomial)


        
if __name__ == '__main__':            

    p1 = Polinomials("4x + 2")
    p2 = Polinomials("2x + 6z")
    p3 = p1 + p2
    print(p3)
    p3 = Polinomials(p3)
    # p3()

    if p1 == p2:
        print(True)
    else:
        print(False)
    # print(p1)

    # e1 = Equation("2x + 3y = 24") # Let x = 6, y = 4
    # e2 = Equation("3x + 4y = 34") # Let x = 6, y = 4

