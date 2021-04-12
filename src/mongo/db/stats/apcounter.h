#pragma once

#include "mongo/platform/atomic_word.h"
#include "mongo/platform/basic.h"
#include "mongo/db/jsobj.h"

namespace mongo {

class ApCounter {
    public:
    ApCounter();
    void gotReadNotAp();
    void gotReadAp();
    void gotErrorGetApExecutorPool();

    void gotReadSlowLog();
    void gotWriteSlowLog();
    void gotFamSlowLog();
    void gotCmdSlowLog();

    //limit counter
    void gotLegacyConnectionLimit();
    void gotAsioWaitReqQueueLimit();
    void gotShardHostLimit();

    BSONObj getObj() const;

    const AtomicUInt32* getReadNotAp() const{
        return &_readNotAp;
    }

    const AtomicUInt32* getReadAp() const {
        return &_readAp;
    }

    const AtomicUInt32* getErrorGetApExecutorPool() const {
        return &_readApExecutorPoolError;
    }

    const AtomicUInt32* getReadSlowLog() const {
        return &_readSlowLog;
    }
    const AtomicUInt32* getWriteSlowLog() const {
        return &_writeSlowLog;
    }
    const AtomicUInt32* getFamSlowLog() const {
        return &_famSlowLog;
    }
    const AtomicUInt32* getCmdSlowLog() const {
        return &_cmdSlowLog;
    }

    // for limiter
    const AtomicUInt32* getLegacyConnectionLimit() const {
        return &_legacyConnectionLimit;
    }
    const AtomicUInt32* getAsioWaitReqQueueLimit() const {
        return &_asioWaitReqQueueLimit;
    }
    const AtomicUInt32* getShardHostLimit() const {
        return &_shardHostLimit;
    }

    private:
    
        void _checkWrap();
        AtomicUInt32 _readNotAp;
        AtomicUInt32 _readAp;
        AtomicUInt32 _readApExecutorPoolError;

        AtomicUInt32 _readSlowLog;
        AtomicUInt32 _writeSlowLog;
        AtomicUInt32 _famSlowLog;
        AtomicUInt32 _cmdSlowLog;

        // connection limit
        AtomicUInt32 _legacyConnectionLimit;
        AtomicUInt32 _asioWaitReqQueueLimit;
        AtomicUInt32 _shardHostLimit;
};

extern ApCounter globalApCounter;
}