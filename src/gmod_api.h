#pragma once
#include<string>
#include<functional>

#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

DLLEXPORT void hello();

namespace mcl_basic {

DLLEXPORT class IHolistic 
{
    public:
        virtual void Setup(int cam_id, int cam_resx, int cam_resy, int cam_fps, bool gpu) = 0;
        virtual void Start() = 0;
        virtual void Stop() = 0;
        virtual std::vector<std::vector<float>>* GetData() = 0;
};

DLLEXPORT IHolistic* CreateHolistic();

} // namespace mcl_basic

namespace mcl {

DLLEXPORT class IObserver
{
    public:
        virtual void SetPresenceCallback(std::function<void(class IObserver*, bool)> in_presence_callback)=0;
        virtual void SetPacketCallback(std::function<void(class IObserver*)> in_packet_callback)=0;
        virtual std::string GetMessageType()=0;
        virtual const void* const GetData()=0;
};

DLLEXPORT class IGMOD
{
    public:
        virtual bool get_camera() = 0;
        virtual void set_camera(bool x) = 0;
        virtual bool get_overlay() = 0;
        virtual void set_overlay(bool x) = 0;

        virtual void set_camera_props(int cam_id, int cam_resx, int cam_resy, int cam_fps) = 0;

        virtual IObserver* create_observer(const char* stream_name) = 0;

        virtual bool is_loaded() = 0;

        virtual void start(const char* filename) = 0;
        virtual void stop() = 0;
};

DLLEXPORT IGMOD* CreateGMOD();

} // namespace mcl