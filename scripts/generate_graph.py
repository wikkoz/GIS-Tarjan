import sys
import json
import argparse


def generate_dense(size):
    print('Dense edges not implemented yet!')
    exit(1)


def generate_long_list(size):
    return [{
                FIRST_VERTEX: str(i),
                SECOND_VERTEX: str(i+1)
             } for i in range(size-1)]


def generate_big_star(size):
    return [{
        FIRST_VERTEX: '0',
        SECOND_VERTEX: str(i)
    } for i in range(1, size)]


def generate_list_with_stars(size):
    edges = []
    n_list = int(size / 3) + size % 3 + 1
    n_star1 = n_star2 = int ((size - n_list) / 2)

    st_list = 1
    sp_list = st_list + n_list

    root_star1 = 0
    st_star1 = sp_list
    sp_star1 = st_star1 + n_star1

    root_star2 = sp_list - 1
    st_star2 = sp_star1
    sp_star2 = st_star2 + n_star2

    # List
    edges.extend([{
        FIRST_VERTEX: str(i - 1),
        SECOND_VERTEX: str(i)
    } for i in range(st_list, sp_list)])

    # Star 1
    edges.extend([{
        FIRST_VERTEX: str(root_star1),
        SECOND_VERTEX: str(i)
    } for i in range(st_star1, sp_star1)])

    # Star 2
    edges.extend([{
        FIRST_VERTEX: str(root_star2),
        SECOND_VERTEX: str(i)
    } for i in range(st_star2, sp_star2)])

    print(json.dumps(edges, indent=4))


VERTICES = 'vertices'
EDGES = 'edges'
FIRST_VERTEX = 'firstVertex'
SECOND_VERTEX = 'secondVertex'

GENERATORS = {
    'dense': generate_dense,
    'long_list': generate_long_list,
    'big_star': generate_big_star,
    'list_with_stars': generate_list_with_stars
}


def generate(args):
    size = args.size
    type = args.type

    vertices = [str(i) for i in range(size)]
    edges = GENERATORS[type](size)

    return vertices, edges


class Graph:
    content = {}

    def __init__(self, vertices, edges):
        self.content[VERTICES] = vertices
        self.content[EDGES] = edges

    def save(self, filename):
        with open(filename, 'w') as f:
            content = json.dumps(self.content, indent=4)
            f.write(content)


def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument('-t', '--type', type=str, choices=GENERATORS.keys(), required=True,
                        help='Type of graph')
    parser.add_argument('-n', '--size', type=int, required=True,
                        help='Graph size')
    parser.add_argument('-o', '--output', type=str, required=True,
                        help='Output name')
    args = parser.parse_args()

    if args.size < 1:
        print('Invalid graph size!')
        sys.exit(1)

    return args


def main():
    try:
        args = parse_args()
        output = args.output
        vertices, edges = generate(args)
        graph = Graph(vertices, edges)
        graph.save(output)
    except (KeyboardInterrupt, SystemExit):
        pass


main()
