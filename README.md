# Presentatation at Everything Open 2024

by me.

Contents:
* Dockerfile for building a rr in a container.
* example.cc - a puzzle
* example.out - a compiled puzzle from example.cc with the right* compiler incantation.

sysctl kernel.perf_event_paranoid=1


podman tag quay.io/danielgblack/rr rr
podman volume create rec
podman run --rm --privileged  -v rec:/root/.local rr rr record /example.out


Note: * for very small values of right.
