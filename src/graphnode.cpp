#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    // delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

// void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
// void GraphNode::MoveChatbotHere(ChatBot *chatbot)
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    std::cout << "Check point 3" << std::endl;
    // _chatBot = &chatbot;
    _chatBot = std::move(chatbot);
    std::cout << "Check point 4" << std::endl;
    // _chatBot->SetCurrentNode(this);
    _chatBot.SetCurrentNode(this);
    std::cout << "Check point 5" << std::endl;
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    std::cout << "Check point 6" << std::endl;
    newNode->MoveChatbotHere(std::move(_chatBot));
    // _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}