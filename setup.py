
from distutils.core import setup, Extension

def main():
    setup(name="pyrocketry",
    version="0.1.0",
    description="Python interface for rocket equations",
    author="Serhii Stets",
    author_email="stets.serhii@gmail.com",
    ext_modules=[Extension("pyrocketry", ["pyrocketry/pyrocketry.c"])])

if __name__ == "__main__":
    main()
