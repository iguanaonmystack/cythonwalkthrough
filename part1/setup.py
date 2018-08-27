from setuptools import setup, find_packages, Extension
from Cython.Build import cythonize

ext_modules = []

ext_modules.append(Extension(
    'walkthrough.cbigproduct',
    sources=['walkthrough/cbigproductmodule.c']))

ext_modules.extend(cythonize('walkthrough/bigproduct.py'))
ext_modules.extend(cythonize('walkthrough/*.pyx'))

setup(
    name='Walkthrough',
    version='1.0',
    description='Package for A Cython Walkthrough',
    packages=find_packages(),
    ext_modules=ext_modules,
)
