"""
Module
"""
class Array:
    """
    Class
    """

    def __init__(self) -> None:
        pass
    def __call__(self) -> object:
        pass

    # Representation
    def __repr__(self) -> str:
        pass
    def __str__(self) -> str:
        pass

    # Arithmetic Operators
    def __add__(self, other) -> object:
        pass
    def __iadd__(self, other) -> object:
        pass
    def __sub__(self, other) -> object:
        pass
    def __isub__(self, other) -> object:
        pass
    def __mul__(self, other) -> object:
        pass
    def __imul__(self, other) -> object:
        pass
    def __div__(self, other) -> object:
        pass
    def __truediv__(self, other) -> object:
        pass
    def __itruediv__(self, other) -> object:
        pass
    def __floordiv__(self, other) -> object:
        pass
    def __ifloordiv__(self, other) -> object:
        pass
    def __mod__(self, other) -> object:
        pass
    def __imod__(self, other) -> object:
        pass
    def __pow__(self, other) -> object:
        pass
    def __ipow__(self, other) -> object:
        pass
    def __abs__(self) -> object:
        pass

    # Comparison Operators
    def __lt__(self, other) -> bool:
        pass
    def __le__(self, other) -> bool:
        pass
    def __eq__(self, other) -> bool:
        pass
    def __ge__(self, other) -> bool:
        pass
    def __gt__(self, other) -> bool:
        pass
    def __ne__(self, other) -> bool:
        pass
    def __not__(self) -> bool:
        pass
    def __and__(self, other) -> bool:
        pass
    def __or__(self, other) -> bool:
        pass
    def __bool__(self) -> bool:
        pass

    # Item Operations (Get/Set)
    def __getitem__(self, index) -> object:
        pass
    def __setitem__(self, index, value) ->None:
        pass
    def __delitem__(self, index) -> None:
        pass
    def __contains__(self, value) -> bool:
        pass

    # Loop Operators
    def __iter__(self) -> iter:
        pass
    def __len__(self) -> int:
        pass

    # Object Operations
    def append(self, value) -> None:
        """Inserts a value to the end of the Array"""

    def prepend(self, value) -> None:
        """Inserts a value to the start of the Array"""

    def insert(self, index, value) -> None:
        """Inserts a value to the given index in the Array"""

    def remove(self, value) -> None:
        """Removes the first occurrence of the specified value from the Array"""

    def remove_all(self, value) -> None:
        """Removes all occurrences of the specified value from the Array"""

    def find(self, value) -> int:
        """Returns the index of the first occurrence of the specified value in the Array"""

    def find_all(self, value) ->list:
        """Returns a list of the indices of the occurrences of the specified value in the Array"""

    def count_occurrences(self, value) -> int:
        """Returns the number of occurrences of the specified value in the Array"""

    def sort(self, sort_type) -> None:
        """Sorts the elements of the Array according to the sort type specified"""

    def reverse(self) -> None:
        """Reverse the elements of the Array"""

    def to_list(self) -> list:
        """Returns a list of the elements"""

    def negate(self, value) -> None:
        """Change the signs of all the elements in the Array"""
