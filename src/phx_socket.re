open Phx_abstract;
type t = {
  .
  /*constructor(endPoint: string, opts?: Object);*/
  /*defined as function*/
  /*protocol(): string;*/
  [@bs.get] "protocol": string,
  /*endPointURL(): string;*/
  [@bs.get] "endPointURL": string,
  /*disconnect(callback?: Function, code?: string, reason?: any): void;*/
  /*defined as function since bs doesn't allow method to be curried*/
  /*connect(params?: any): void;*/
  /*defined as function since bs doesn't allow method to be curried*/
  /*log(kind: string, msg: string, data: any): void;*/
  [@bs.meth] "log": (string, string, any) => void,
  /*onOpen(callback: Function): void;*/
  [@bs.meth] "onOpen": function_ => void,
  /*onClose(callback: Function): void;*/
  [@bs.meth] "onClose": function_ => void,
  /*onError(callback: Function): void;*/
  [@bs.meth] "onError": function_ => void,
  /*onMessage(callback: Function): void;*/
  [@bs.meth] "onMessage": function_ => void,
  /*onConnOpen(): void;*/
  [@bs.get] "onConnOpen": void,
  /*onConnClose(event: any): void;*/
  [@bs.meth] "onConnClose": any => void,
  /*onConnError(error: any): void;*/
  [@bs.meth] "onConnError": any => void,
  /*triggerChanError(): void;*/
  [@bs.get] "triggerChanError": void,
  /*connectionState(): string;*/
  [@bs.get] "connectionState": string,
  /*isConnected(): boolean;*/
  [@bs.get] "isConnected": bool,
  /*remove(channel: Channel): void;*/
  [@bs.meth] "remove": Phx_channel.t => void,
  /*channel(topic: string, chanParams?: Object): Channel;*/
  /*defined as function since bs doesn't allow method to be curried*/
  /*push(data: any): void;*/
  [@bs.meth] "push": any => void,
  /*makeRef(): string;*/
  [@bs.get] "makeRef": string,
  /*sendHeartbeat(): void;*/
  [@bs.get] "sendHeartbeat": void,
  /*flushSendBuffer(): void;*/
  [@bs.get] "flushSendBuffer": void,
  /*onConnMessage(rawMessage: any): void;*/
  [@bs.meth] "onConnMessage": any => void,
};

/*constructor(endPoint: string, opts?: Object);*/
[@bs.new] [@bs.module "phoenix"]
external init: (string, ~opts: Js.t('opts)=?, unit) => t = "Socket";
let init = (~opts: option(Js.t('opts))=?, path) => init(path, ~opts?, ());

/* Chris McCord: "The Channel's consturctor is private. You should only create channel instances off the socket's channel/2 function." */
/*constructor(topic: string, params?: Object, socket?: Socket);*/
[@bs.new] [@bs.module "phoenix"]
external initChannel:
  (string, ~params: Js.t('params)=?, ~socket: t=?, unit) => Phx_channel.t =
  "Channel";
let initChannel = (~params=?, ~socket=?, topic) =>
  initChannel(topic, ~params?, ~socket?, ());

/*channel(topic: string, chanParams?: Object): Channel;*/
[@bs.send]
external channel:
  (t, string, ~chanParams: Js.t('chanParams)=?, unit) => Phx_channel.t =
  "channel";
let channel = (topic, ~chanParams=?, socket) =>
  channel(socket, topic, ~chanParams?, ());

/*disconnect(callback?: Function, code?: string, reason?: any): void;*/
[@bs.send]
external disconnect:
  (
    t,
    ~callback: function_=?,
    ~code: string=?,
    ~reason: Js.t('reason)=?,
    unit
  ) =>
  void =
  "disconnect";
let disconnect =
    (
      ~callback: option(function_)=?,
      ~code: option(string)=?,
      ~reason: option(Js.t('reason))=?,
      socket,
    ) => {
  let _ = disconnect(~callback?, ~code?, ~reason?, socket, ());
  socket;
};

/*connect(params?: any): void;*/
[@bs.send]
external connect: (t, ~params: Js.t('params)=?, unit) => void = "connect";
let connect = (~params: option(Js.t('params))=?, socket) => {
  let _ = connect(~params?, socket, ());
  socket;
};
