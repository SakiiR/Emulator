#!/usr/bin/env python
#
# Script used to generate implementation of handler based on their prototypes
# Exemple:
# t_ihandler            i_ld8_a_a;
# t_ihandler            i_ld8_a_b;
#  --
# int                   i_ld8_a_a(t_cpustate *state)
# {
#   (void)state;
#   return RETURN_SUCCESS;
# }

import sys

TEMPLATE = """
int                 %s(t_cpustate *state)
{
    (void)state;
    return RETURN_SUCCESS;
}
"""


def main(argv):

    """ Main process """

    output = ""
    content = ""
    with open(argv[1], 'r') as f:
        content = f.read()
        f.close()
    lines = content.splitlines()
    for line in lines:
        if line[:10] == 't_ihandler':
            proto_name = line.split()[1].rstrip(';')
            output += TEMPLATE % proto_name
    print(output)


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("USAGE: ./proto2imp.py <file>")
    else:
        main(sys.argv)
