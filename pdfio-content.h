//
// Public content header file for PDFio.
//
// Copyright © 2021 by Michael R Sweet.
//
// Licensed under Apache License v2.0.  See the file "LICENSE" for more
// information.
//

#ifndef PDFIO_CONTENT_H
#  define PDFIO_CONTENT_H

//
// Include necessary headers...
//

#  include "pdfio.h"


//
// C++ magic...
//

#  ifdef __cplusplus
extern "C" {
#  endif // __cplusplus


//
// Types and constants...
//

typedef enum pdfio_linecap_e		// Line capping modes
{
  PDFIO_LINECAP_BUTT,			// Butt ends
  PDFIO_LINECAP_ROUND,			// Round ends
  PDFIO_LINECAP_SQUARE			// Square ends
} pdfio_linecap_t;

typedef enum pdfio_linejoin_e		// Line joining modes
{
  PDFIO_LINEJOIN_MITER,			// Miter joint
  PDFIO_LINEJOIN_ROUND,			// Round joint
  PDFIO_LINEJOIN_BEVEL			// Bevel joint
} pdfio_linejoin_t;

typedef double pdfio_matrix_t[3][2];	// Transform matrix

typedef enum pdfio_textrendering_e	// Text rendering modes
{
  PDFIO_TEXTRENDERING_FILL,		// Fill text
  PDFIO_TEXTRENDERING_STROKE,		// Stroke text
  PDFIO_TEXTRENDERING_FILL_AND_STROKE,	// Fill then stroke text
  PDFIO_TEXTRENDERING_INVISIBLE,	// Don't fill or stroke (invisible)
  PDFIO_TEXTRENDERING_FILL_PATH,	// Fill text and add to path
  PDFIO_TEXTRENDERING_STROKE_PATH,	// Stroke text and add to path
  PDFIO_TEXTRENDERING_FILL_AND_STROKE_PATH,
					// Fill then stroke text and add to path
  PDFIO_TEXTRENDERING_TEXT_PATH		// Add text to path (invisible)
} pdfio_textrendering_t;

extern const double	pdfioAdobeRGBGamma PDFIO_PUBLIC;
					// AdobeRGB gamma
extern const double	pdfioAdobeRGBMatrix[3][3] PDFIO_PUBLIC;
					// AdobeRGB matrix
extern const double	pdfioAdobeRGBWhitePoint[3] PDFIO_PUBLIC;
					// AdobeRGB white point
extern const double	pdfioDisplayP3Gamma PDFIO_PUBLIC;
					// Display P3 gamma
extern const double	pdfioDisplayP3Matrix[3][3] PDFIO_PUBLIC;
					// Display P3 matrix
extern const double	pdfioDisplayP3WhitePoint[3] PDFIO_PUBLIC;
					// Display P3 white point
extern const double	pdfioSRGBGamma PDFIO_PUBLIC;
					// sRGB gamma
extern const double	pdfioSRGBMatrix[3][3] PDFIO_PUBLIC;
					// sRGB matrix
extern const double	pdfioSRGBWhitePoint[3] PDFIO_PUBLIC;
					// sRGB white point


//
// Functions...
//

// Color array functions...
extern pdfio_array_t	*pdfioArrayCreateColorFromICCObj(pdfio_file_t *pdf, pdfio_obj_t *icc_object) PDFIO_PUBLIC;
extern pdfio_array_t	*pdfioArrayCreateColorFromMatrix(pdfio_file_t *pdf, size_t num_colors, double gamma, const double matrix[3][3], const double white_point[3]) PDFIO_PUBLIC;
extern pdfio_array_t	*pdfioArrayCreateColorFromPalette(pdfio_file_t *pdf, size_t num_colors, const unsigned char *colors) PDFIO_PUBLIC;
extern pdfio_array_t	*pdfioArrayCreateColorFromPrimaries(pdfio_file_t *pdf, size_t num_colors, double gamma, double wx, double wy, double rx, double ry, double gx, double gy, double bx, double by) PDFIO_PUBLIC;

// PDF content drawing functions...
extern bool		pdfioContentClip(pdfio_stream_t *st, bool even_odd) PDFIO_PUBLIC;
extern bool		pdfioContentDrawImage(pdfio_stream_t *st, const char *name, double x, double y, double w, double h) PDFIO_PUBLIC;
extern bool		pdfioContentFill(pdfio_stream_t *st, bool even_odd) PDFIO_PUBLIC;
extern bool		pdfioContentFillAndStroke(pdfio_stream_t *st, bool even_odd) PDFIO_PUBLIC;
extern bool		pdfioContentMatrixConcat(pdfio_stream_t *st, pdfio_matrix_t m) PDFIO_PUBLIC;
extern bool		pdfioContentMatrixRotate(pdfio_stream_t *st, double degrees) PDFIO_PUBLIC;
extern bool		pdfioContentMatrixScale(pdfio_stream_t *st, double sx, double sy) PDFIO_PUBLIC;
extern bool		pdfioContentMatrixTranslate(pdfio_stream_t *st, double tx, double ty) PDFIO_PUBLIC;
extern bool		pdfioContentPathClose(pdfio_stream_t *st) PDFIO_PUBLIC;
extern bool		pdfioContentPathCurve(pdfio_stream_t *st, double x1, double y1, double x2, double y2, double x3, double y3) PDFIO_PUBLIC;
extern bool		pdfioContentPathCurve13(pdfio_stream_t *st, double x1, double y1, double x3, double y3) PDFIO_PUBLIC;
extern bool		pdfioContentPathCurve23(pdfio_stream_t *st, double x2, double y2, double x3, double y3) PDFIO_PUBLIC;
extern bool		pdfioContentPathLineTo(pdfio_stream_t *st, double x, double y) PDFIO_PUBLIC;
extern bool		pdfioContentPathMoveTo(pdfio_stream_t *st, double x, double y) PDFIO_PUBLIC;
extern bool		pdfioContentPathRect(pdfio_stream_t *st, double x, double y, double width, double height) PDFIO_PUBLIC;
extern bool		pdfioContentRestore(pdfio_stream_t *st) PDFIO_PUBLIC;
extern bool		pdfioContentSave(pdfio_stream_t *st) PDFIO_PUBLIC;
extern bool		pdfioContentSetDashPattern(pdfio_stream_t *st, int phase, int on, int off) PDFIO_PUBLIC;
extern bool		pdfioContentSetFillColorDeviceCMYK(pdfio_stream_t *st, double c, double m, double y, double k) PDFIO_PUBLIC;
extern bool		pdfioContentSetFillColorDeviceGray(pdfio_stream_t *st, double g) PDFIO_PUBLIC;
extern bool		pdfioContentSetFillColorDeviceRGB(pdfio_stream_t *st, double r, double g, double b) PDFIO_PUBLIC;
extern bool		pdfioContentSetFillColorGray(pdfio_stream_t *st, double g) PDFIO_PUBLIC;
extern bool		pdfioContentSetFillColorRGB(pdfio_stream_t *st, double r, double g, double b) PDFIO_PUBLIC;
extern bool		pdfioContentSetFillColorSpace(pdfio_stream_t *st, const char *name) PDFIO_PUBLIC;
extern bool		pdfioContentSetFlatness(pdfio_stream_t *st, double f) PDFIO_PUBLIC;
extern bool		pdfioContentSetLineCap(pdfio_stream_t *st, pdfio_linecap_t lc) PDFIO_PUBLIC;
extern bool		pdfioContentSetLineJoin(pdfio_stream_t *st, pdfio_linejoin_t lj) PDFIO_PUBLIC;
extern bool		pdfioContentSetLineWidth(pdfio_stream_t *st, double width) PDFIO_PUBLIC;
extern bool		pdfioContentSetMiterLimit(pdfio_stream_t *st, double limit) PDFIO_PUBLIC;
extern bool		pdfioContentSetStrokeColorDeviceCMYK(pdfio_stream_t *st, double c, double m, double y, double k) PDFIO_PUBLIC;
extern bool		pdfioContentSetStrokeColorDeviceGray(pdfio_stream_t *st, double g) PDFIO_PUBLIC;
extern bool		pdfioContentSetStrokeColorDeviceRGB(pdfio_stream_t *st, double r, double g, double b) PDFIO_PUBLIC;
extern bool		pdfioContentSetStrokeColorGray(pdfio_stream_t *st, double g) PDFIO_PUBLIC;
extern bool		pdfioContentSetStrokeColorRGB(pdfio_stream_t *st, double r, double g, double b) PDFIO_PUBLIC;
extern bool		pdfioContentSetStrokeColorSpace(pdfio_stream_t *st, const char *name) PDFIO_PUBLIC;
extern bool		pdfioContentSetTextCharacterSpacing(pdfio_stream_t *st, double spacing) PDFIO_PUBLIC;
extern bool		pdfioContentSetTextFont(pdfio_stream_t *st, const char *name, double size) PDFIO_PUBLIC;
extern bool		pdfioContentSetTextLeading(pdfio_stream_t *st, double leading) PDFIO_PUBLIC;
extern bool		pdfioContentSetTextMatrix(pdfio_stream_t *st, pdfio_matrix_t m) PDFIO_PUBLIC;
extern bool		pdfioContentSetTextRenderingMode(pdfio_stream_t *st, pdfio_textrendering_t mode) PDFIO_PUBLIC;
extern bool		pdfioContentSetTextRise(pdfio_stream_t *st, double rise) PDFIO_PUBLIC;
extern bool		pdfioContentSetTextWordSpacing(pdfio_stream_t *st, double spacing) PDFIO_PUBLIC;
extern bool		pdfioContentSetTextXScaling(pdfio_stream_t *st, double percent) PDFIO_PUBLIC;
extern bool		pdfioContentStroke(pdfio_stream_t *st) PDFIO_PUBLIC;
extern bool		pdfioContentTextBegin(pdfio_stream_t *st) PDFIO_PUBLIC;
extern bool		pdfioContentTextEnd(pdfio_stream_t *st) PDFIO_PUBLIC;
extern bool		pdfioContentTextMoveLine(pdfio_stream_t *st, double tx, double ty) PDFIO_PUBLIC;
extern bool		pdfioContentTextMoveTo(pdfio_stream_t *st, double tx, double ty) PDFIO_PUBLIC;
extern bool		pdfioContentTextNextLine(pdfio_stream_t *st) PDFIO_PUBLIC;
extern bool		pdfioContentTextShow(pdfio_stream_t *st, bool unicode, const char *s) PDFIO_PUBLIC;
extern bool		pdfioContentTextShowf(pdfio_stream_t *st, bool unicode, const char *format, ...) PDFIO_PUBLIC PDFIO_FORMAT(3,4);
extern bool		pdfioContentTextShowJustified(pdfio_stream_t *st, bool unicode, size_t num_fragments, const double *offsets, const char * const *fragments) PDFIO_PUBLIC;

// Resource helpers...
extern pdfio_obj_t	*pdfioFileCreateFontObjFromBase(pdfio_file_t *pdf, const char *name) PDFIO_PUBLIC;
extern pdfio_obj_t	*pdfioFileCreateFontObjFromFile(pdfio_file_t *pdf, const char *filename, bool unicode) PDFIO_PUBLIC;
extern pdfio_obj_t	*pdfioFileCreateICCObjFromFile(pdfio_file_t *pdf, const char *filename, size_t num_colors) PDFIO_PUBLIC;
extern pdfio_obj_t	*pdfioFileCreateImageObjFromData(pdfio_file_t *pdf, const unsigned char *data, size_t width, size_t height, int num_colors, pdfio_array_t *color_data, bool interpolate) PDFIO_PUBLIC;
extern pdfio_obj_t	*pdfioFileCreateImageObjFromFile(pdfio_file_t *pdf, const char *filename, bool interpolate) PDFIO_PUBLIC;

// Image object helpers...
extern size_t		pdfioImageGetBytesPerLine(pdfio_obj_t *obj) PDFIO_PUBLIC;
extern double		pdfioImageGetHeight(pdfio_obj_t *obj) PDFIO_PUBLIC;
extern double		pdfioImageGetWidth(pdfio_obj_t *obj) PDFIO_PUBLIC;

// Page dictionary helpers...
extern bool		pdfioPageDictAddColorSpace(pdfio_dict_t *dict, const char *name, pdfio_array_t *data) PDFIO_PUBLIC;
extern bool		pdfioPageDictAddFont(pdfio_dict_t *dict, const char *name, pdfio_obj_t *obj) PDFIO_PUBLIC;
extern bool		pdfioPageDictAddImage(pdfio_dict_t *dict, const char *name, pdfio_obj_t *obj) PDFIO_PUBLIC;


//
// C++ magic...
//

#  ifdef __cplusplus
}
#  endif // __cplusplus
#endif // !PDFIO_CONTENT_H
