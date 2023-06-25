class New_Type(type):
    def __repr__(self) -> str:
        return self.__name__

class Polynomial(metaclass = New_Type):
    # Defining Errors...
    exponentialConstant = "Invalid Polynomial! : Adding Exponent To Constant Is Not A Valid Polynomial Syntax!!!"
    
    # Defining Some Dunder/Magic/Special Methods(Functions)...
    def __init__(self, polynomial : str = "x + y + 1") -> None:
        self.polynomial = polynomial
        self.data = Polynomial.deconstruct_Polynomial(polynomial)

    def __repr__(self) -> str:
        if len(self.data['variables']) == 1 and self.data['variables'][0] is None:
            string = "< Constant Object Belonging To Class Polynomial."
        elif len(self.data['variables']) == 1:
            string = "< Monomial Object Belonging To Class Polynomial."
        elif len(self.data['variables']) == 2:
            string = "< Binomial Object Belonging To Class Polynomial."
        elif len(self.data['variables']) == 3:
            string = "< Trinomial Object Belonging To Class Polynomial."
        else:
            string = f"< Polynomial Object With {len(self.data['variables'])} Terms."
        return string + f" Expression: {self.polynomial} >"

    def __str__(self) -> str:
        return str(self.polynomial)

    def __call__(self, show_Dicts:bool = False):
        if show_Dicts is False:
            print("\nExtracting Data From The Polynomial Object...\n")
            for index in range(len(self.data['variables'])):
                print(f"< [Term No. {index + 1} : {self.data['monomials'][index]}] Variable: {self.data['variables'][index]} | Constant: {self.data['constants'][index]} | Exponent: {self.data['exponents'][index]} >")
            print("\nPolynomial Object Data Extraction Complete.\n")
        else:
            print("\nExtracting Data From The Polynomial Object...\n")
            print(f"Variables: {self.data['variables']}")
            print(f"Constants: {self.data['constants']}")
            print(f"Exponents: {self.data['exponents']}")
            print("\nPolynomial Object Data Extraction Complete.\n")

    def __add__(self, other: object):
        string = ""
        if len(self.data['variables']) >= len(other.data['variables']):
            for index in range(len(self.data['variables'])):
                temp = string
                for monomial in range(len(other.data['variables'])):
                    if self.data['variables'][index] == other.data['variables'][monomial] and self.data['exponents'][index] == other.data['exponents'][monomial]:
                        # print(f"Variable Matched: {self.data['variables'][index]} | {self.data['constants'][index]} + {other.data['constants'][monomial]} = {self.data['constants'][index] + other.data['constants'][monomial]}")
                        if self.data['variables'][index] != None:
                            if self.data['constants'][index] + other.data['constants'][monomial] < 0:
                                string += f"{self.data['constants'][index] + other.data['constants'][monomial]}{self.data['variables'][index]} "
                            else:
                                string += f"+ {self.data['constants'][index] + other.data['constants'][monomial]}{self.data['variables'][index]} "
                        else:
                            if self.data['constants'][index] + other.data['constants'][monomial] < 0:
                                string += f"{self.data['constants'][index] + other.data['constants'][monomial]} "
                            else:
                                string += f"+ {self.data['constants'][index] + other.data['constants'][monomial]} "


                if temp == string:
                    if self.data['constants'][index] + other.data['constants'][monomial] < 0:
                        if self.data['variables'][index] != None:
                            string += f"{self.data['constants'][index]}{self.data['variables'][index]} "
                        else:
                            string += f"{self.data['constants'][index]} "
                    else:
                        if self.data['variables'][index] != None:
                            string += f"+ {self.data['constants'][index]}{self.data['variables'][index]} "
                        else:
                            string += f"+ {self.data['constants'][index]} "
        else:
            for index in range(len(other.data['variables'])):
                temp = string
                for monomial in range(len(self.data['variables'])):
                    if other.data['variables'][index] == self.data['variables'][monomial] and other.data['exponents'][index] == self.data['exponents'][monomial]:
                        if other.data['variables'][index] != None:
                            if self.data['constants'][index] + other.data['constants'][monomial] < 0:
                                string += f"{self.data['constants'][index] + other.data['constants'][monomial]}{other.data['variables'][index]} "
                            else:
                                string += f"+ {self.data['constants'][index] + other.data['constants'][monomial]}{other.data['variables'][index]} "
                        else:
                            if self.data['constants'][index] + other.data['constants'][monomial] < 0:
                                string += f"{self.data['constants'][index] + other.data['constants'][monomial]} "
                            else:
                                string += f"+ {self.data['constants'][index] + other.data['constants'][monomial]} "
                            
                if temp == string:
                    if index < len(self.data['constants']):    
                        if other.data['variables'][index] != None:
                            if self.data['constants'][index] + other.data['constants'][monomial] < 0:
                                string += f"{other.data['constants'][index]}{other.data['variables'][index]} "
                        else:
                            string += f"{other.data['constants'][index]} "
                    else:
                        if other.data['variables'][index] != None:
                            string += f"+ {other.data['constants'][index]}{other.data['variables'][index]} "
                        else:
                            string += f"+ {other.data['constants'][index]} "

        if string[0] == '+':
            string = string[2: ]

        return string

    def __sub__(self, other: object):
        string = ""
        if len(self.data['variables']) >= len(other.data['variables']):
            for index in range(len(self.data['variables'])):
                temp = string
                for monomial in range(len(other.data['variables'])):
                    if self.data['variables'][index] == other.data['variables'][monomial] and self.data['exponents'][index] == other.data['exponents'][monomial]:
                        # print(f"Variable Matched: {self.data['variables'][index]} | {self.data['constants'][index]} + {other.data['constants'][monomial]} = {self.data['constants'][index] + other.data['constants'][monomial]}")
                        if self.data['constants'][index] + other.data['constants'][monomial] < 0:
                            string += f"{self.data['constants'][index] - other.data['constants'][monomial]}{self.data['variables'][index]} "
                        else:
                            string += f"+{self.data['constants'][index] - other.data['constants'][monomial]}{self.data['variables'][index]} "

                if temp == string:
                    if self.data['constants'][index] + other.data['constants'][monomial] < 0:
                        string += f"{self.data['constants'][index]}{self.data['variables'][index]} "
                    else:
                        string += f"+{self.data['constants'][index]}{self.data['variables'][index]} "
        else:
            for index in range(len(other.data['variables'])):
                temp = string
                for monomial in range(len(self.data['variables'])):
                    if other.data['variables'][index] == self.data['variables'][monomial] and other.data['exponents'][index] == self.data['exponents'][monomial]:
                        if self.data['constants'][index] + other.data['constants'][monomial] < 0:
                            string += f"{self.data['constants'][index] - other.data['constants'][monomial]}{other.data['variables'][index]} "
                        else:
                            string += f"+{self.data['constants'][index] - other.data['constants'][monomial]}{other.data['variables'][index]} "
                            
                if temp == string:
                    if index < len(self.data['constants']):
                        if self.data['constants'][index] + other.data['constants'][monomial] < 0:
                            string += f"{other.data['constants'][index]}{other.data['variables'][index]} "
                    else:
                        string += f"+{other.data['constants'][index]}{other.data['variables'][index]} "

        if string[0] == '+':
            string = string[1: ]  
        for i in range(len(string) - 1):
            if string[i] == '+' and string[i + 1] == '-':
                string = string[ :i] + string[i+1: ]

        return string

    def __eq__(self, other: object) -> bool:
        if str(self.polynomial) == str(other.polynomial):
            return True
        if len(self.data['variables']) != len(other.data['variables']):
            return False
        else:
            for index in range(len(self.data['variables'])):
                value = False
                for dex in range(len(other.data['variables'])):
                    if self.data['variables'][index] == other.data['variables'][dex]:
                        if self.data['constants'][index] == other.data['constants'][dex]:
                            if self.data['exponents'][index] == other.data['exponents'][dex]:
                                value = True
                                break
                if not value:
                    return False
            return True


    # Defining Some Static Methods...
    @staticmethod
    def deconstruct_Polynomial(polynomial : str, monomial_Needed : bool = True) -> dict:
        data = {
            "variables" : {},
            "constants" : {},
            "exponents" : {}
        }

        polynomial1 = polynomial.replace(' ', '')
        l = polynomial1.split('+')
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
            if Polynomial._is_Variable(string):

                if '^' in string:
                    exponent = string.find('^')
                    data["exponents"][index] = int(string[exponent + 1])
                    data["variables"][index] = string[exponent - 1]
                    data["constants"][index] = int(string.split(string[exponent - 1])[0])

                elif len(string) >= 2:
                    variable = len(string) - 1
                    data["exponents"][index] = 1
                    data["variables"][index] = string[variable]
                    data["constants"][index] = int(string.split(string[variable])[0])

                else:
                    data["exponents"][index] = 1
                    data["variables"][index] = string[0]
                    data["constants"][index] = 1

            else:

                if '^' in string: 
                    raise Exception(Polynomial.exponentialConstant)
                data["exponents"][index] = 1 
                data["variables"][index] = None
                data["constants"][index] = int(string)
        if monomial_Needed:
            data["monomials"] = l1

        return data

    @staticmethod
    def _is_Variable(monomial : str) -> bool:
        import string
        legal_Variables = list(string.ascii_lowercase)
        for variable in legal_Variables:
            if variable in monomial:
                return True
        return False

    @staticmethod
    def reconstruct_Polynomial(data:dict) -> str:
        poly_Str = ""
        for variable, constant, exponent in zip(data["variables"].values(), data["constants"].values(), data["exponents"].values()):

            poly_Str += f" - {abs(constant)}" if constant < 0 else f" + {abs(constant)}"
            poly_Str += f"{variable}" if variable != None else ""
            poly_Str += f"^{exponent}" if exponent > 1 else ""
        
        return poly_Str

    @staticmethod
    def dissimilar_Monomials(polynomial1 : object, polynomial2 : object) -> list[dict]:
        data = {
            "variables": {},
            "constants": {},
            "exponents": {}
        }
        index = 0;
        poly1_vars = polynomial1.data['variables'].values()
        poly2_vars = polynomial2.data['variables'].values()

        for i, var in enumerate(poly1_vars):
            if var not in poly2_vars:
                data["variables"][index] = polynomial1.data['variables'][i]
                data["constants"][index] = polynomial1.data['constants'][i]
                data["exponents"][index] = polynomial1.data['exponents'][i]
                index += 1
        for i, var in enumerate(poly2_vars):
            if var not in poly1_vars:
                data["variables"][index] = polynomial2.data['variables'][i]
                data["constants"][index] = polynomial2.data['constants'][i]
                data["exponents"][index] = polynomial2.data['exponents'][i]
                index += 1
        return data
                


    # Defining Some Private Methods ...



class Equations(metaclass = New_Type):

    def __init__(self, equation: str) -> None:
        self.equation = equation
        self.LHS, self.RHS = equation.split('=')
        self.Left_Polynomial = Polynomial(self.LHS)
        self.Right_Polynomial = Polynomial(self.RHS)
        print(self.Left_Polynomial)
        print(self.Right_Polynomial)

        
if __name__ == '__main__':            

    # print(Polynomial.reconstruct_Polynomial(Polynomial.deconstruct_Polynomial("")))

    p1 = Polynomial("4x + 2")
    p2 = Polynomial("2x + 6z")
    p3 = p1 + p2
    print(p3)
    p3 = Polynomial(p3)


    p3(True)
    p3()

    print(f"Printing:  {Polynomial.dissimilar_Monomials(p1, p2)}")

    if p1 == p2:
        print(True)
    else:
        print(False)
    print(p1)
    print(p2)
    print(p3)

    # e1 = Equation("2x + 3y = 24") # Let x = 6, y = 4
    # e2 = Equation("3x + 4y = 34") # Let x = 6, y = 4

