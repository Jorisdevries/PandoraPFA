/**
 *  @file   PandoraPFANew/include/Helpers/FragmentRemovalHelper.h
 * 
 *  @brief  Header file for the fragment removal helper class.
 * 
 *  $Log: $
 */
#ifndef FRAGMENT_REMOVAL_HELPER_H
#define FRAGMENT_REMOVAL_HELPER_H 1

#include "Pandora/PandoraInternal.h"

namespace pandora
{

/**
 *  @brief  FragmentRemovalHelper class
 */
class FragmentRemovalHelper
{
public:
    /**
     *  @brief  Get the fraction of calo hits in cluster I that lie within a specified distance of a calo hit in cluster J
     * 
     *  @param  pClusterI address of the cluster for which the fraction is calculated
     *  @param  pClusterJ address of the cluster used in the comparison
     *  @param  distanceThreshold the specified distance threshold
     */
    static float GetFractionOfCloseHits(const Cluster *const pClusterI, const Cluster *const pClusterJ, const float distanceThreshold);

    /**
     *  @brief  Get the fraction of calo hits in cluster I that lie within a cone along the direction of cluster J.
     *          If cluster J has an associated track, it's projected position and direction at the ecal will be used to define cone,
     *          otherwise cone will be radial and its axis will pass through centroid of cluster J at its showermax layer.
     * 
     *  @param  pClusterI address of the cluster for which the fraction is calculated
     *  @param  pClusterJ address of the cluster used in the comparison
     *  @param  coneCosineHalfAngle
     */
    static float GetFractionOfHitsInCone(const Cluster *const pClusterI, const Cluster *const pClusterJ, const float coneCosineHalfAngle);

    /**
     *  @brief  Get the number of pseudo layers crossed by helix in specified range of z coordinates
     * 
     *  @param  pHelix address of the helix
     *  @param  zStart start z coordinate
     *  @param  zEnd end z coordinate
     *  @param  nSamplingPoints number of points at which to sample the helix in the z interval
     */
    static PseudoLayer GetNLayersCrossed(const Helix *const pHelix, const float zStart, const float zEnd, const unsigned int nSamplingPoints = 100);
};

} // namespace pandora

#endif // #ifndef FRAGMENT_REMOVAL_HELPER_H
