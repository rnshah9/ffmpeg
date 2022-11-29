FROM --platform=linux/amd64 ubuntu:20.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential nasm pkg-config clang

COPY . /repo
WORKDIR /repo
RUN ./configure --prefix=/install
RUN make -j8
RUN make install    
RUN clang++ /repo/mayhem/fuzz_av_stristr.cpp -fsanitize=fuzzer,address -L /install/lib/ -lavutil -o /fuzz

FROM ubuntu:20.04 as package
COPY --from=builder /install /install
COPY --from=builder /fuzz /fuzz_av_stristr
