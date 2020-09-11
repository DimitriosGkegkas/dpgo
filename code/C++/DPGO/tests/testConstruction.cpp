#include "gtest/gtest.h"
#include "distributed/PGOAgent.h"

using namespace DPGO;

TEST(testDPGO, Construction)
{
    unsigned int id = 1;
    unsigned int d,r;
    d = 3;
    r = 3;
    ROPTALG algorithm = ROPTALG::RTR;
    bool verbose = false;
    PGOAgentParameters options(d,r,algorithm,verbose);

    PGOAgent agent(id, options);

    ASSERT_EQ(agent.getID(), id);
    ASSERT_EQ(agent.getCluster(), id);
    ASSERT_EQ(agent.num_poses(), 1);
    ASSERT_EQ(agent.dimension(), d);
    ASSERT_EQ(agent.relaxation_rank(), r);
    ASSERT_GE(agent.gradNorm(), 0);
}