#!/usr/bin/env python3

import os
import argparse

def constructParser(parser):
  parser.add_argument('-v', '--verbose', action='count', help="increase output verbosity")
  parser.add_argument('-s', "--server_path", help="specify path of bus server executable file")
  parser.add_argument('-c', "--config", help="specify path of configuration file")
  parser.add_argument('-b', "--background", action='store_true', help="run in the background")
  parser.add_argument('-k', "--kill", action='store_true', help="kill all bus instances")

def main():
  bin_path = './a.out'
  background = False

  parser = argparse.ArgumentParser()
  constructParser(parser)
  args = parser.parse_args()

  if args.verbose:
    print(args.verbose)
  if args.server_path:
    print("path changed")
    bin_path = args.server_path
  if args.background:
    print("background")
    background = True
  if args.kill:
    print("not supported yet")

  start(bin_path, background)


def start(bin_path, background):
  cmd = bin_path
  if background:
    os.system(cmd + '&')
  else:
    os.system(cmd)

if __name__ == "__main__":
    main()
