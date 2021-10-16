#include<algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Probe
{
    float pos[3];
    vector<int> mBrickIndex;
};

struct Brick
{
    float pos[3];
    vector<int> mSurfellIndex;
};

struct Surfel
{
    float pos[3];
};

struct SectorData
{
    vector<Surfel> mSurfels;
    vector<Brick> mBricks;
    vector<Probe> mProbe;
};

struct NewSurfel
{
    float pos[3];
};

struct NewBrick
{
    float pos[3];
    float weight;
    vector<NewSurfel> surfelData;
};

struct NewProbe
{
    float pos[3];
    vector<NewBrick> brickData;
};


NewSurfel creteNewSurfel(Surfel& surfel, SectorData& origion)
{
    NewSurfel ret;
    for(int i=0; i < sizeof(surfel.pos); i++)
    {
        ret.pos[i] = surfel.pos[i];
    }
    return ret;
}

NewBrick createNewBrick(Brick& brick, float weight, SectorData& origion)
{
    NewBrick ret;
    for(int i=0; i < sizeof(brick.pos); i++)
    {
        ret.pos[i] = brick.pos[i];
    }
    ret.weight = weight;
    for(int i= 0; i < brick.mSurfellIndex.size(); ++i)
    {
        ret.surfelData.emplace_back(creteNewSurfel(origion.mSurfels[brick.mSurfellIndex[i]], origion));
    }
    sort(ret.surfelData.begin(), ret.surfelData.end(), [](const NewSurfel& a, const NewSurfel& b)
    {
        for (int i=0; i < sizeof(a.pos); ++i)
        {
            if (abs(a.pos[i]-b.pos[i]) < 0.001)
            {
                return a.pos[i] < b.pos[i];
            }
        }
        return false;
    });
    return ret;
}

NewProbe createNewProbe(Probe& probe, SectorData& origion)
{
    NewProbe ret;
    for(int i=0; i < sizeof(probe.pos); i++)
    {
        ret.pos[i] = probe.pos[i];
    }
    for(int i=0; i < probe.mBrickIndex.size(); ++i)
    {
        ret.brickData.emplace_back(createNewBrick(origion.mBricks[probe.mBrickIndex[i]], probe.mBrickWeight[i], origion));
    }
    sort(ret.brickData.begin(), ret.brickData.end(), [](const NewBreak& a, const NewBreak& b)
    {
        for (int i=0; i < sizeof(a.pos); ++i)
        {
            if (abs(a.pos[i]-b.pos[i]) < 0.001)
            {
                return a.pos[i] < b.pos[i];
            }
        }
        return a.weight < b.weight;
    });
    return ret;
}

SectorData process(SectorData& origion)
{
    vector<NewProbe> data;
    for(auto i=0; i < origion.mProbe.size(); ++i)
    {
        data.emplace_back(createNewProbe(origion.mProbe[i], origion));
    }
    sort(data.begin(), data.end(), [](const NewProbe& a, const NewProbe& b)
    {
        for (int i=0; i < sizeof(a.pos); ++i)
        {
            if (abs(a.pos[i]-b.pos[i]) < 0.001)
            {
                return a.pos[i] < b.pos[i];
            }
        }
        return true;
    });
}

int main(void)
{
    cout << "hello world" <<endl;
    return 0;
}