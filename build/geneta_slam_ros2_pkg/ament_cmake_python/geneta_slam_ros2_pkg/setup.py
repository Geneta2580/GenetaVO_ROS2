from setuptools import find_packages
from setuptools import setup

setup(
    name='geneta_slam_ros2_pkg',
    version='0.0.0',
    packages=find_packages(
        include=('geneta_slam_ros2_pkg', 'geneta_slam_ros2_pkg.*')),
)
