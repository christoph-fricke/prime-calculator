"""
Contains the Prime class which contains methods for checking prime numbers
"""


from math import ceil

if __name__ == '__main__':
    exit("Module can't be executed as main script!")


class Prime:
    """Contains methods for checking primes"""
    @staticmethod
    def is_prime(number):
        """Retruns true if number is a prime. Else false"""
        if number == 2:
            return True
        elif number == 1 or (number > 2 and number % 2 == 0):
            return False

        for divisor in range(3, ceil(number**(1 / 2)), 2):
            if number % divisor == 0:
                return False
        return True
