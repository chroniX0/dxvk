#pragma once

#include "d3d11_device_child.h"

namespace dxvk {
  
  class D3D11Device;
  
  class D3D11InputLayout : public D3D11DeviceChild<ID3D11InputLayout> {
    
  public:
    
    D3D11InputLayout(
            D3D11Device*                pDevice,
            uint32_t                    numAttributes,
      const DxvkVertexAttribute*        pAttributes,
            uint32_t                    numBindings,
      const DxvkVertexBinding*          pBindings);
    
    ~D3D11InputLayout();
    
    HRESULT QueryInterface(
            REFIID  riid,
            void**  ppvObject) final;
    
    void GetDevice(
            ID3D11Device **ppDevice) final;
    
    void BindToContext(
      const Rc<DxvkContext>& ctx);
    
  private:
    
    D3D11Device* const  m_device;
    
    std::vector<DxvkVertexAttribute> m_attributes;
    std::vector<DxvkVertexBinding>   m_bindings;
    
  };
  
}