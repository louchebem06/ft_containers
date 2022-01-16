# FT_CONTAINERS_CHECKER

<p align="center">
	<img src="./assets/ft_containers_checker.gif" >
</p>

### Reacreating containers: Vector, Stack, Map

A C++ project for 42 school...

Git clone this in the root of your ft_containers project or edit the path variable in the script...

Or just copy/paste this :
```bash
git clone https://github.com/busshi/ft_containers_checker.git && cd ft_containers_checker && /bin/bash grademe.sh
```


Usage:
```bash
./grademe.sh [ vector | stack | map ] # to test each container separately
./grademe.sh # to test everything
./grademe.sh one [path_to_test_file] # to make only one test
```

Example:
```bash:
./grademe.sh one srcs/vector/01_ctor.cpp --no-leak # will test only vector constructors and skip leak test
```

Note:
- This script does not check if it is slower or faster than STL. Validation is made comparing output for ft_container and std_container...
- Edit header names in case it is not "vector.hpp" / "stack.hpp" / "map.hpp" in the file located in srcs/$CONTAINER/Cont.hpp
- Add "--no-leak" option after arguments to skip leak tests
