#ifndef _LEAF_INPUT_FINDER_H_
#define _LEAF_INPUT_FINDER_H_
#if defined(_MSC_VER)
#pragma once
#endif

/*
 * LEGAL NOTICE
 * This computer software was prepared by Battelle Memorial Institute,
 * hereinafter the Contractor, under Contract No. DE-AC05-76RL0 1830
 * with the Department of Energy (DOE). NEITHER THE GOVERNMENT NOR THE
 * CONTRACTOR MAKES ANY WARRANTY, EXPRESS OR IMPLIED, OR ASSUMES ANY
 * LIABILITY FOR THE USE OF THIS SOFTWARE. This notice including this
 * sentence must appear on any copies of this computer software.
 * 
 * EXPORT CONTROL
 * User agrees that the Software will not be shipped, transferred or
 * exported into any country or used in any manner prohibited by the
 * United States Export Administration Act or any other applicable
 * export laws, restrictions or regulations (collectively the "Export Laws").
 * Export of the Software may require some form of license or other
 * authority from the U.S. Government, and failure to obtain such
 * export control license may result in criminal liability under
 * U.S. laws. In addition, if the Software is identified as export controlled
 * items under the Export Laws, User represents and warrants that User
 * is not a citizen, or otherwise located within, an embargoed nation
 * (including without limitation Iran, Syria, Sudan, Cuba, and North Korea)
 *     and that User is not otherwise prohibited
 * under the Export Laws from receiving the Software.
 * 
 * Copyright 2011 Battelle Memorial Institute.  All Rights Reserved.
 * Distributed as open-source under the terms of the Educational Community 
 * License version 2.0 (ECL 2.0). http://www.opensource.org/licenses/ecl2.php
 * 
 * For further details, see: http://www.globalchange.umd.edu/models/gcam/
 * 
 */

/*! 
* \file leaf_input_finder.h
* \ingroup Objects
* \brief The LeafInputFinder class header file.
*
* \author Pralit Patel
*/

#include <vector>
#include "util/base/include/default_visitor.h"

class IInput;
class SGMInput;

/*! 
* \ingroup Objects
* \brief Finds any input leaves in a nested input structure.
* \details Currently only SGMInput is considered a leaf.
* \todo Add a visit method for any other type of input which sould be considered a leaf.
* \author Pralit Patel
*/
class LeafInputFinder : public DefaultVisitor {
public:
    LeafInputFinder();

    std::vector<IInput*> getInputs() const;

    // IVisitor methods
    virtual void startVisitSGMInput( const SGMInput* aSGMInput, const int aPeriod );
    // TODO: put a visit for any other type of input which could be a leaf here

private:
    //! The vector of found leaves accumulated during visiting
    std::vector<IInput*> mInputs;
};

#endif // _LEAF_INPUT_FINDER_H_
