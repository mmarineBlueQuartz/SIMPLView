///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2009, Michael A. Jackson. BlueQuartz Software
//  Copyright (c) 2009, Michael Groeber, US Air Force Research Laboratory
//  All rights reserved.
//  BSD License: http://www.opensource.org/licenses/bsd-license.html
//
// This code was partly written under US Air Force Contract FA8650-07-D-5800
//
///////////////////////////////////////////////////////////////////////////////
#ifndef _GrainGeneratorFunc_H
#define _GrainGeneratorFunc_H

#if defined (_MSC_VER)
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#endif

#include <assert.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include <cstddef>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <fstream>
#include <list>
#include <algorithm>
#include <numeric>

#include <MXA/MXATypes.h>
#include <MXA/Common/MXASetGetMacros.h>

#include "AIM/Common/AIMCommonConfiguration.h"
#include "AIM/Common/Constants.h"
#include "AIM/Common/Grain.h"
#include "AIM/Common/Voxel.h"
#include "AIM/Common/Bin.h"
#include "AIM/Common/AIMRandomNG.h"
#include "AIM/Reconstruction/H5ReconStatsReader.h"


using namespace std;

/**
 * @class GrainGeneratorFunc GrainGeneratorFunc.h AIM/Common/GrainGeneratorFunc.h
 * @brief
 * @author
 * @date
 * @version 1.0
 */
class AIMCOMMON_EXPORT GrainGeneratorFunc
{

public:

    MXA_SHARED_POINTERS(GrainGeneratorFunc)
    MXA_STATIC_NEW_MACRO(GrainGeneratorFunc)

  virtual ~GrainGeneratorFunc();

  double resx;
  double resy;
  double resz;
  double sizex;
  double sizey;
  double sizez;

  double misorientationtolerance;
  AIM::Reconstruction::CrystalStructure crystruct;

	AIMRandomNG rg;

	Bin* actualodf;
	Bin* simodf;
	Bin* axisodf;
	Bin* precipaxisodf;
	Voxel* voxels;
	Bin* actualmdf;
	Bin* simmdf;
	Bin* actualmicrotex;
	Bin* simmicrotex;

  Grain* precipitates;
  int* psizes;
  vector<Grain> grains;

	vector<int> gsizes;
	vector<int> activegrainlist;
	vector<int> precipitateorder;
	vector<int> takencheck;
	vector<double> grainsizedist;
	vector<double> precipsizedist;
	vector<vector<double> > bovera;
	vector<vector<double> > covera;
	vector<vector<double> > coverb;
	vector<vector<double> > precipbovera;
	vector<vector<double> > precipcovera;
	vector<vector<double> > precipcoverb;
	vector<vector<double> > neighborhood;
	vector<vector<double> > svomega3;
	vector<vector<double> > precipsvomega3;
	vector<vector<double> > neighbordist;

	void initialize(int32_t m_NumGrains, int32_t m_ShapeClass,
	                double m_XResolution, double m_YResolution, double m_ZResolution,
	                int32_t m_OverlapAllowed,
	                int32_t m_OverlapAssignment, int32_t m_Precipitates,
	                AIM::Reconstruction::CrystalStructure m_CrystalStructure, double m_FractionPrecipitates);
	void initialize2();
	double machineepsilon;
	double maxrealnumber;
	double minrealnumber;
	int numorients;
	int numeulers;
	int resdiff;
	double totalsurfacearea;
	int numgrains;
	int numextragrains;
	int numprecipitates;
	int shapeclass;
	int preciptype;
	int maxdiameter;
	int mindiameter;
	int maxprecipdiameter;
	int minprecipdiameter;
	double fractionprecip;
	double avgdiam;
	double sddiam;
	double avgprecipdiam;
	double sdprecipdiam;
	int numdiameters;
	int worstgrain;
	int numprecipdiameters;


	int32_t xpoints;
	int32_t ypoints;
	int32_t zpoints;
	int totalpoints;
	double totalvol;

	int numneighbins;
	double volcheck;
	int ownercheck;

	double currentfillingerror,oldfillingerror;
	double currentneighborhooderror,oldneighborhooderror;
	double currentsizedisterror,oldsizedisterror;

	void write_eulerangles(string);


	int readReconStatsData(H5ReconStatsReader::Pointer h5io);
  int readAxisOrientationData(H5ReconStatsReader::Pointer h5io);
  int readODFData(H5ReconStatsReader::Pointer h5io);
  int readMisorientationData(H5ReconStatsReader::Pointer h5io);
  int readMicroTextureData(H5ReconStatsReader::Pointer h5io);


	void generate_grain(int);
	void assign_eulers(int);
	void insert_grain(int);
	void add_grain(int);
	void remove_grain(int);
	double costcheck_remove(int);
	double costcheck_add(int);
	void determine_neighbors();
	double check_neighborhooderror(int gadd, int gremove);
	double check_sizedisterror(int gadd, int gremove);
	int pack_grains(int);
	int assign_voxels(int);
	void fill_gaps(int);
	int create_precipitates();
	void insert_precipitates(int);
	void read_structure(string);
	void find_neighbors();
	void writeCube(string, int);

	void matchCrystallography(const std::string &ErrorFile);
	void measure_misorientations();

	double gamma(double);
	double erf(double);
	double erfc(double);
	double gammastirf(double);
	double lngamma(double, double&);
	double incompletebeta(double, double, double);
	double incompletebetafe(double, double, double, double, double);
	double incompletebetafe2(double, double, double, double, double);
	double incompletebetaps(double, double, double, double);
	void write_graindata(string, string);
	double find_xcoord(long);
	double find_ycoord(long);
	double find_zcoord(long);

protected:
  GrainGeneratorFunc();

private:
	GrainGeneratorFunc(const GrainGeneratorFunc&);    // Copy Constructor Not Implemented
    void operator=(const GrainGeneratorFunc&);  // Operator '=' Not Implemented
};


#endif
