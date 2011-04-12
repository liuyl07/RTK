#ifndef __itkConstantImageSource_h
#define __itkConstantImageSource_h

#include "itkImageSource.h"
#include "itkNumericTraits.h"

namespace itk
{

/** \class ConstantImageSource
 * \brief Generate an n-dimensional image with constant pixel values.
 *
 * ConstantImageSource generates an image with constant value.
 *
 * \ingroup DataSources Multithreaded
 */
template <typename TOutputImage>
class ITK_EXPORT ConstantImageSource : public ImageSource<TOutputImage>
{
public:
  /** Standard class typedefs. */
  typedef ConstantImageSource       Self;
  typedef ImageSource<TOutputImage> Superclass;
  typedef SmartPointer<Self>        Pointer;
  typedef SmartPointer<const Self>  ConstPointer;

  /** Typedef for the output image type. */
  typedef TOutputImage OutputImageType;

  /** Typedef for the output image PixelType. */
  typedef typename TOutputImage::PixelType OutputImagePixelType;

  /** Typedef to describe the output image region type. */
  typedef typename TOutputImage::RegionType OutputImageRegionType;

  /** Run-time type information (and related methods). */
  itkTypeMacro(ConstantImageSource,ImageSource);

  /** Method for creation through the object factory. */
  itkNewMacro(Self);
  
  /** Basic types from the OutputImageType */
  typedef typename TOutputImage::SizeType         SizeType;
  typedef typename TOutputImage::IndexType        IndexType;
  typedef typename TOutputImage::SpacingType      SpacingType;
  typedef typename TOutputImage::PointType        PointType;
  typedef typename SizeType::SizeValueType        SizeValueType;
  typedef SizeValueType                           SizeValueArrayType[TOutputImage::ImageDimension];
  typedef typename TOutputImage::SpacingValueType SpacingValueType;
  typedef SpacingValueType                        SpacingValueArrayType[TOutputImage::ImageDimension];
  typedef typename TOutputImage::PointValueType   PointValueType;
  typedef PointValueType                          PointValueArrayType[TOutputImage::ImageDimension];

  /** Set/Get size of the output image */
  itkSetMacro( Size, SizeType );
  virtual void SetSize( SizeValueArrayType sizeArray );
  virtual const SizeValueType * GetSize() const;

  /** Set/Get spacing of the output image */
  itkSetMacro( Spacing, SpacingType );
  virtual void SetSpacing( SpacingValueArrayType spacingArray );
  virtual const SpacingValueType * GetSpacing() const;

  /** Set/Get origin of the output image */
  itkSetMacro( Origin, PointType );
  virtual void SetOrigin( PointValueArrayType originArray );
  virtual const PointValueType * GetOrigin() const;
  
  /** Set/Get the pixel value of output */
  itkSetMacro(Constant, OutputImagePixelType);
  itkGetConstMacro(Constant, OutputImagePixelType);

protected:
  ConstantImageSource();
  ~ConstantImageSource();
  void PrintSelf(std::ostream& os, Indent indent) const;
  
  void ThreadedGenerateData(const OutputImageRegionType& outputRegionForThread, int threadId );
  virtual void GenerateOutputInformation();

private:
  ConstantImageSource(const ConstantImageSource&); //purposely not implemented
  void operator=(const ConstantImageSource&); //purposely not implemented

  SizeType       m_Size;    //size of the output image
  SpacingType    m_Spacing; //spacing
  PointType      m_Origin;  //origin

  typename TOutputImage::PixelType m_Constant;

  // The following variables are deprecated, and provided here just for
  // backward compatibility. It use is discouraged.
  mutable  PointValueArrayType      m_OriginArray;
  mutable  SpacingValueArrayType    m_SpacingArray;

};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkConstantImageSource.txx"
#endif

#endif
