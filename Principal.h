
#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <geos/geom/PrecisionModel.h>
#include <geos/geom/GeometryFactory.h>
#include <geos/geom/Geometry.h>
#include <geos/geom/Point.h>
#include <geos/geom/LinearRing.h>
#include <geos/geom/LineString.h>
#include <geos/geom/Polygon.h>
#include <geos/geom/GeometryCollection.h>
#include <geos/geom/Coordinate.h>
#include <geos/geom/CoordinateSequence.h>
#include <geos/geom/CoordinateArraySequence.h>
#include <geos/geom/IntersectionMatrix.h>
#include <geos/io/WKBReader.h>
#include <geos/io/WKBWriter.h>
#include <geos/io/WKTWriter.h>
#include <geos/util/GeometricShapeFactory.h>
#include <geos/util/GEOSException.h>
#include <geos/util/IllegalArgumentException.h>
#include <geos/opLinemerge.h>
#include <geos/opPolygonize.h>

#include <string>
#include <vector>

#ifndef M_PI
#define M_PI       3.14159265358979323846
#endif

// Set to 0 to skip section
#define GEOMETRIC_SHAPES 1
#define RELATIONAL_OPERATORS 1
#define COMBINATIONS 1
#define UNARY_OPERATIONS 1
#define LINEMERGE 1
#define POLYGONIZE 1

#include "gdal_priv.h"
#include "cpl_conv.h"


using namespace std;
using namespace geos;
using namespace geos::geom;
using namespace geos::operation::polygonize;
using namespace geos::operation::linemerge;

/**
  * class Principal
  * 
  */

class Principal
{
public:

    Principal ( );
    virtual ~Principal ( );

    Point * create_point (double x, double y);
    GDALDataset *poDataset;

protected:

    GeometryFactory *global_factory;
    vector<Geometry *> *geoms;
    
    
private:

};

#endif // PRINCIPAL_H