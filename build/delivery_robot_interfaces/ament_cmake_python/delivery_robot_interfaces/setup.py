from setuptools import find_packages
from setuptools import setup

setup(
    name='delivery_robot_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('delivery_robot_interfaces', 'delivery_robot_interfaces.*')),
)
