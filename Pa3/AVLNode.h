#pragma once
#include "CancerData.h"
class AVLNode {
public:
    AVLNode(CancerData data, AVLNode* leftp, AVLNode* rightp, int height)
        : pData(data), pLeft(leftp), pRight(rightp), mHeight(height) {}

    AVLNode* getLeftp() const { return pLeft; }
    AVLNode* getRightP() const { return pRight; }
    CancerData& getData() { return pData; }
    int getHeight() const { return mHeight; }
    void setLeftp(AVLNode* node) { pLeft = node; }
    void setRightp(AVLNode* node) { pRight = node; }
    void setheight(int height) { mHeight = height; }
    AVLNode*& getLeftpRef() {
        return pLeft;
    }

    AVLNode*& getRightpRef() {
        return pRight;
    }

private:
    CancerData pData;
    AVLNode* pLeft;
    AVLNode* pRight;
    int mHeight;
};


