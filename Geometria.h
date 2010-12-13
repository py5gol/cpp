#ifndef GEOMETRIA_H
#define GEOMETRIA_H

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
#include <geos/io/WKTReader.h>
#include <geos/io/WKTWriter.h>
#include <geos/util/GeometricShapeFactory.h>
#include <geos/util/GEOSException.h>
#include <geos/util/IllegalArgumentException.h>
#include <geos/opLinemerge.h>
#include <geos/opPolygonize.h>

#include <string>
#include <list>

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

using namespace std;
using namespace geos;
using namespace geos::geom;
using namespace geos::operation::polygonize;
using namespace geos::operation::linemerge;


/**
  * class Geometria
  * 
  */

class Geometria
{
protected:
    int codigo;
    int tipo;
    Geometry * geometria;
    
public:
    Geometria (int, Geometry *);
    virtual ~Geometria ();

    int getCodigo ();
    virtual int getTipo () = 0;
    Geometry * getGeometria ();
    
    virtual float getIvdnMedio () = 0;
    virtual void imprimeInfo () = 0;
};

#endif // GEOMETRIA_H
