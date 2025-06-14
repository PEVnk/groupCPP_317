/**************************************************************************************
 * Filename: t4.cpp
 * Developer: Perkova Elena
 * Description: ������ୠ� 8
 * ��᫥������� � �++ �⠭���⭮� ������⥪� 蠡����� (STL), ��ॣ�㧪� �����஢
 * ***********************************************************************************/

#include <iostream>
#include "lab8.h"


TreeNode::TreeNode(int val) : value(val) {}

TreeNode::~TreeNode() {
  for (auto child : children) {
    delete child;
  }
}

TreeNode* TreeNode::AddChild(int child_value) {
  auto node = new TreeNode(child_value);
  node->parent = this;
  children.push_back(node);
  return node;
}

void TreeNode::Print(int depth) const {
  for (int i = 0; i < depth; ++i) {
    std::cout << " ";
  }
  std::cout << "- " << value << "\n";
  for (const auto& child : children) {
    child->Print(depth + 1);
  }
}
