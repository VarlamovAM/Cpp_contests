class IOWrapper{
    public:
        IOWrapper(handle_t handle): handle(handle){};

        ~IOWrapper(){
            if (handle != kNullHandle)
            raw_close(handle);
        }

        IOWrapper(IOWrapper&& src) {
            handle = src.handle;
            src.handle = kNullHandle;
        }

        IOWrapper& operator=(IOWrapper &&src){
            handle = src.handle;
            src.handle = kNullHandle;
            return *this;
        }

        IOWrapper() = delete;
        IOWrapper(IOWrapper const &src) = delete;
        IOWrapper& operator=(IOWrapper const &src) = delete;

        void Write(const std::string& content){
            raw_write(handle, content);
        }
    private:
        handle_t handle;
};
