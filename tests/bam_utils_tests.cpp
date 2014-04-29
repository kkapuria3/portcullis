//  ********************************************************************
//  This file is part of Portculis.
//
//  Portculis is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  Portculis is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with Portculis.  If not, see <http://www.gnu.org/licenses/>.
//  *******************************************************************

#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#define BOOST_TEST_MODULE PORTCULIS
#endif
#include <boost/test/unit_test.hpp>

#include <boost/filesystem.hpp>

#include <bam_utils.hpp>

using std::cout;
using std::endl;

BOOST_AUTO_TEST_SUITE(bam_utils)

BOOST_AUTO_TEST_CASE(merge)
{
    // Merge a couple of BAMs together
    vector<string> bamFiles;
    bamFiles.push_back("resources/bam1.bam");
    bamFiles.push_back("resources/bam2.bam");
    
    string mergedBam = "resources/merged.bam";
    portculis::mergeBams(bamFiles, mergedBam);
    
    // Check the merged bam file exists
    BOOST_CHECK(boost::filesystem::exists(mergedBam));
    
    // Delete the merged bam file
    boost::filesystem::remove(mergedBam);
}


BOOST_AUTO_TEST_SUITE_END()
