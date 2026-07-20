# Setup
FROM ubuntu:latest
WORKDIR /cpp_node/

# Install dependacies
RUN apt-get update
RUN apt-get install gcc -y
RUN apt-get install g++ -y
RUN apt-get install git -y
RUN apt-get install make -y
RUN apt-get install cmake -y
RUN apt-get install googletest -y
RUN apt-get update
RUN apt-get upgrade -y

# Copy source code
COPY makefile /cpp_node/
COPY CMakeLists.txt /cpp_node/
COPY .gitignore /cpp_node/
COPY src/ /cpp_node/src/
COPY test/ /cpp_node/test/

# Compile and build
RUN make all
RUN cmake -S . -B build/
RUN cmake --build build/

# Run Test
RUN ctest --test-dir build/

# Run on entrance
CMD [ "/cpp_node/cpp_node" ]
