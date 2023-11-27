from anytree import Node, RenderTree
from anytree.exporter import DotExporter
import pydot

udo = Node("1 3 2\n5 4 8\n6 7 0")
marc = Node("1 2 3\n5 4 8\n6 7 0", parent=udo)
lian = Node("1 2 3\n4 5 8\n6 7 0", parent=marc)
dan = Node("1 3 2\n5 4 8\n6 0 7", parent=udo)
jet = Node("Jet", parent=dan)
jat = Node("Jat", parent=dan)
joe = Node("Joe", parent=dan)

for pre, fill, node in RenderTree(udo):
  print("%s%s" % (pre, node.name))

