FROM fedora as base

RUN dnf install -y cmake curl capnproto-devel capnproto gcc-c++ unzip zlib-devel   python3-pexpect gdb ninja-build

RUN curl https://codeload.github.com/rr-debugger/rr/zip/refs/heads/master -o master.zip && unzip master.zip && rm master.zip

RUN mkdir build \
    && cd build \
    && cmake \
             -Ddisable32bit=ON \
             -G Ninja \
              ../rr-master \
    && cmake --build . \
    && cmake --install . --prefix /rr/usr/local

FROM fedora

COPY --from=base /rr/usr/local /usr/
RUN dnf install -y gdb lldb capnproto-libs

COPY example.out /

RUN mkdir /root/.local
VOLUME /root/.local/
